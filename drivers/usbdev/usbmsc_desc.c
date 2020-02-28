/****************************************************************************
 * drivers/usbdev/usbmsc_desc.c
 *
 *   Copyright (C) 2011-2012, 2015, 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/usb/usb.h>
#include <nuttx/usb/usbdev_trace.h>

#include "usbmsc.h"

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Descriptors **************************************************************/

/* Device descriptor.  If the USB mass storage device is configured as part
 * of a composite device, then the device descriptor will be provided by the
 * composite device logic.
 */

#ifndef CONFIG_USBMSC_COMPOSITE
static const struct usb_devdesc_s g_devdesc =
{
  USB_SIZEOF_DEVDESC,                           /* len */
  USB_DESC_TYPE_DEVICE,                         /* type */
  {LSBYTE(0x0200), MSBYTE(0x0200)},             /* usb */
  USB_CLASS_PER_INTERFACE,                      /* classid */
  0,                                            /* subclass */
  0,                                            /* protocol */
  CONFIG_USBMSC_EP0MAXPACKET,                   /* maxpacketsize */
  {                                             /* vendor */
    LSBYTE(CONFIG_USBMSC_VENDORID),
    MSBYTE(CONFIG_USBMSC_VENDORID)
  },
  {                                             /* product */
    LSBYTE(CONFIG_USBMSC_PRODUCTID),
    MSBYTE(CONFIG_USBMSC_PRODUCTID) },
  {                                             /* device */
    LSBYTE(CONFIG_USBMSC_VERSIONNO),
    MSBYTE(CONFIG_USBMSC_VERSIONNO)
  },
  USBMSC_MANUFACTURERSTRID,                     /* imfgr */
  USBMSC_PRODUCTSTRID,                          /* iproduct */
  USBMSC_SERIALSTRID,                           /* serno */
  USBMSC_NCONFIGS                               /* nconfigs */
};
#endif

#ifdef CONFIG_USBDEV_DUALSPEED
#ifndef CONFIG_USBMSC_COMPOSITE
static const struct usb_qualdesc_s g_qualdesc =
{
  USB_SIZEOF_QUALDESC,                          /* len */
  USB_DESC_TYPE_DEVICEQUALIFIER,                /* type */
  {                                             /* usb */
    LSBYTE(0x0200),
    MSBYTE(0x0200)
  },
  USB_CLASS_PER_INTERFACE,                      /* classid */
  0,                                            /* subclass */
  0,                                            /* protocol */
  CONFIG_USBMSC_EP0MAXPACKET,                   /* mxpacketsize */
  USBMSC_NCONFIGS,                              /* nconfigs */
  0,                                            /* reserved */
};
#endif
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* Strings ******************************************************************/

#ifndef CONFIG_USBMSC_COMPOSITE
const char g_mscvendorstr[]  = CONFIG_USBMSC_VENDORSTR;
const char g_mscproductstr[] = CONFIG_USBMSC_PRODUCTSTR;
const char g_mscserialstr[]  = CONFIG_USBMSC_SERIALSTR;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: usbmsc_mkstrdesc
 *
 * Description:
 *   Construct a string descriptor
 *
 ****************************************************************************/

int usbmsc_mkstrdesc(uint8_t id, struct usb_strdesc_s *strdesc)
{
  const char *str;
  int len;
  int ndata;
  int i;

  switch (id)
    {
#ifndef CONFIG_USBMSC_COMPOSITE
    case 0:
      {
        /* Descriptor 0 is the language id */

        strdesc->len     = 4;
        strdesc->type    = USB_DESC_TYPE_STRING;
        strdesc->data[0] = LSBYTE(USBMSC_STR_LANGUAGE);
        strdesc->data[1] = MSBYTE(USBMSC_STR_LANGUAGE);
        return 4;
      }

    case USBMSC_MANUFACTURERSTRID:
      str = g_mscvendorstr;
      break;

    case USBMSC_PRODUCTSTRID:
      str = g_mscproductstr;
      break;

    case USBMSC_SERIALSTRID:
      str = g_mscserialstr;
      break;
#endif

  /* case USBMSC_CONFIGSTRID: */

    case USBMSC_INTERFACESTRID:
      str = CONFIG_USBMSC_CONFIGSTR;
      break;

    default:
      return -EINVAL;
    }

  /* The string is utf16-le.  The poor man's utf-8 to utf16-le
   * conversion below will only handle 7-bit en-us ascii
   */

  len = strlen(str);
  if (len > (USBMSC_MAXSTRLEN / 2))
    {
      len = (USBMSC_MAXSTRLEN / 2);
    }

  for (i = 0, ndata = 0; i < len; i++, ndata += 2)
    {
      strdesc->data[ndata]   = str[i];
      strdesc->data[ndata + 1] = 0;
    }

  strdesc->len  = ndata + 2;
  strdesc->type = USB_DESC_TYPE_STRING;
  return strdesc->len;
}

/****************************************************************************
 * Name: usbmsc_getdevdesc
 *
 * Description:
 *   Return a pointer to the raw device descriptor
 *
 ****************************************************************************/

#ifndef CONFIG_USBMSC_COMPOSITE
FAR const struct usb_devdesc_s *usbmsc_getdevdesc(void)
{
  return &g_devdesc;
}
#endif

/****************************************************************************
 * Name: usbmsc_copy_epdesc
 *
 * Description:
 *   Copies the requested Endpoint Description into the buffer given.
 *   Returns the number of Bytes filled in ( sizeof(struct usb_epdesc_s) ).
 *
 ****************************************************************************/

int usbmsc_copy_epdesc(enum usbmsc_epdesc_e epid,
                       FAR struct usb_epdesc_s *epdesc,
                       FAR struct usbdev_devinfo_s *devinfo,
                       bool hispeed)
{
#ifndef CONFIG_USBDEV_DUALSPEED
    UNUSED(hispeed);
#endif

    switch (epid)
    {
    case USBMSC_EPBULKOUT:  /* Bulk OUT endpoint */
      {
        epdesc->len = USB_SIZEOF_EPDESC;            /* Descriptor length */
        epdesc->type = USB_DESC_TYPE_ENDPOINT;      /* Descriptor type */
        epdesc->addr = USBMSC_MKEPBULKOUT(devinfo); /* Endpoint address */
        epdesc->attr = USBMSC_EPOUTBULK_ATTR;       /* Endpoint attributes */

#ifdef CONFIG_USBDEV_DUALSPEED
        if (hispeed)
          {
            /* Maximum packet size (high speed) */

            epdesc->mxpacketsize[0] = LSBYTE(USBMSC_HSBULKMAXPACKET);
            epdesc->mxpacketsize[1] = MSBYTE(USBMSC_HSBULKMAXPACKET);
          }
        else
#endif
          {
            /* Maximum packet size (full speed) */

            epdesc->mxpacketsize[0] = LSBYTE(USBMSC_FSBULKMAXPACKET);
            epdesc->mxpacketsize[1] = MSBYTE(USBMSC_FSBULKMAXPACKET);
          }

        epdesc->interval = 0;                       /* Interval */
      }
      break;

    case USBMSC_EPBULKIN:  /* Bulk IN endpoint */
      {
        epdesc->len = USB_SIZEOF_EPDESC;            /* Descriptor length */
        epdesc->type = USB_DESC_TYPE_ENDPOINT;      /* Descriptor type */
        epdesc->addr = USBMSC_MKEPBULKIN(devinfo);  /* Endpoint address */
        epdesc->attr = USBMSC_EPINBULK_ATTR;        /* Endpoint attributes */

#ifdef CONFIG_USBDEV_DUALSPEED
        if (hispeed)
          {
            /* Maximum packet size (high speed) */

            epdesc->mxpacketsize[0] = LSBYTE(USBMSC_HSBULKMAXPACKET);
            epdesc->mxpacketsize[1] = MSBYTE(USBMSC_HSBULKMAXPACKET);
          }
        else
#endif
          {
            /* Maximum packet size (full speed) */

            epdesc->mxpacketsize[0] = LSBYTE(USBMSC_FSBULKMAXPACKET);
            epdesc->mxpacketsize[1] = MSBYTE(USBMSC_FSBULKMAXPACKET);
          }

        epdesc->interval = 0;                       /* Interval */
      }
      break;

    default:
        return 0;
    }

  return sizeof(struct usb_epdesc_s);
}

/****************************************************************************
 * Name: usbmsc_mkcfgdesc
 *
 * Description:
 *   Construct the configuration descriptor
 *
 ****************************************************************************/

#ifdef CONFIG_USBDEV_DUALSPEED
int16_t usbmsc_mkcfgdesc(uint8_t *buf,
                         FAR struct usbdev_devinfo_s *devinfo,
                         uint8_t speed, uint8_t type)
#else
int16_t usbmsc_mkcfgdesc(uint8_t *buf,
                        FAR struct usbdev_devinfo_s *devinfo)
#endif
{
  int length = 0;
  bool hispeed = false;

#ifdef CONFIG_USBDEV_DUALSPEED
  hispeed = (speed == USB_SPEED_HIGH);

  /* Check for switches between high and full speed */

  if (type == USB_DESC_TYPE_OTHERSPEEDCONFIG)
    {
      hispeed = !hispeed;
    }
#endif

  /* Fill in all descriptors directly to the buf */

  /* Configuration descriptor.  If the USB mass storage device is
   * configured as part of a composite device, then the configuration
   * descriptor will be provided by the composite device logic.
   */

#ifndef CONFIG_USBMSC_COMPOSITE
  {
    /* Configuration descriptor  If the USB mass storage device is configured as part
     * of a composite device, then the configuration descriptor will be provided
     * by the composite device logic.
     */

    FAR struct usb_cfgdesc_s *dest = (FAR struct usb_cfgdesc_s *)buf;

    dest->len         = USB_SIZEOF_CFGDESC;               /* Descriptor length */
#ifdef CONFIG_USBDEV_DUALSPEED
    dest->type        = type;                             /* Descriptor type */
#else
    dest->type        = USB_DESC_TYPE_CONFIG;             /* Descriptor type */
#endif
    dest->totallen[0] = LSBYTE(SIZEOF_USBMSC_CFGDESC);    /* LS Total length */
    dest->totallen[1] = MSBYTE(SIZEOF_USBMSC_CFGDESC);    /* MS Total length */
    dest->ninterfaces = USBMSC_NINTERFACES;               /* Number of interfaces */
    dest->cfgvalue    = USBMSC_CONFIGID;                  /* Configuration value */
    dest->icfg        = USBMSC_CONFIGSTRID;               /* Configuration */
    dest->attr        = USB_CONFIG_ATTR_ONE |             /* Attributes */
                        USBMSC_SELFPOWERED |
                        USBMSC_REMOTEWAKEUP;
    dest->mxpower     = (CONFIG_USBDEV_MAXPOWER + 1) / 2; /* Max power (mA/2) */

    buf    += sizeof(struct usb_cfgdesc_s);
    length += sizeof(struct usb_cfgdesc_s);
  }
#endif

  /* Copy the canned interface descriptor */

  {
    /* Single interface descriptor */

    FAR struct usb_ifdesc_s * dest = (struct usb_ifdesc_s *)buf;

    dest->len      = USB_SIZEOF_IFDESC;                        /* Descriptor length */
    dest->type     = USB_DESC_TYPE_INTERFACE;                  /* Descriptor type */
    dest->ifno     = devinfo->ifnobase;                        /* Interface number */
    dest->alt      = USBMSC_ALTINTERFACEID;                    /* Alternate setting */
    dest->neps     = USBMSC_NENDPOINTS;                        /* Number of endpoints */
    dest->classid  = USB_CLASS_MASS_STORAGE;                   /* Interface class */
    dest->subclass = USBMSC_SUBCLASS_SCSI;                     /* Interface sub-class */
    dest->protocol = USBMSC_PROTO_BULKONLY;                    /* Interface protocol */
    dest->iif      = devinfo->strbase + USBMSC_INTERFACESTRID; /* iInterface */

    buf    += sizeof(struct usb_ifdesc_s);
    length += sizeof(struct usb_ifdesc_s);
  }

  /* Make the two endpoint configurations */

  /* Bulk IN endpoint descriptor */

  {
    int len = usbmsc_copy_epdesc(USBMSC_EPBULKIN, (FAR struct usb_epdesc_s *)buf,
                                 devinfo, hispeed);

    buf += len;
    length += len;
  }

  /* Bulk OUT endpoint descriptor */

  {
    int len = usbmsc_copy_epdesc(USBMSC_EPBULKOUT,
                                 (FAR struct usb_epdesc_s *)buf, devinfo,
                                 hispeed);

    buf += len;
    length += len;
  }

  return SIZEOF_USBMSC_CFGDESC;
}

/****************************************************************************
 * Name: usbmsc_getqualdesc
 *
 * Description:
 *   Return a pointer to the raw qual descriptor
 *
 ****************************************************************************/

#if !defined(CONFIG_USBMSC_COMPOSITE) && defined(CONFIG_USBDEV_DUALSPEED)
FAR const struct usb_qualdesc_s *usbmsc_getqualdesc(void)
{
  return &g_qualdesc;
}
#endif
