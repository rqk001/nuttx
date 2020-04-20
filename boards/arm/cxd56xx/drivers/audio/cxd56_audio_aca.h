/****************************************************************************
 * boards/arm/cxd56xx/drivers/audio/cxd56_audio_aca.h
 *
 *   Copyright 2018 Sony Semiconductor Solutions Corporation
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
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
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

#ifndef __BOARDS_ARM_CXD56XX_DRIVERS_AUDIO_CXD56_AUDIO_ACA_H
#define __BOARDS_ARM_CXD56XX_DRIVERS_AUDIO_CXD56_AUDIO_ACA_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <arch/chip/audio.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define DNC1_IRAM_BASE  0x3000
#define DNC1_CRAM_BASE  0x3800
#define DNC2_IRAM_BASE  0x3c00
#define DNC2_CRAM_BASE  0x4400

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

CXD56_AUDIO_ECODE cxd56_audio_aca_poweron(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweroff(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweron_micbias(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweron_input(
                                  FAR cxd56_audio_mic_gain_t *gain);
CXD56_AUDIO_ECODE cxd56_audio_aca_set_smaster(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweron_output(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweroff_input(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_poweroff_output(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_enable_output(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_disable_output(void);
CXD56_AUDIO_ECODE cxd56_audio_aca_set_micgain(
                                  FAR cxd56_audio_mic_gain_t *gain);
CXD56_AUDIO_ECODE cxd56_audio_aca_notify_micbootdone(void);

#endif /* __BOARDS_ARM_CXD56XX_DRIVERS_AUDIO_CXD56_AUDIO_ACA_H */
