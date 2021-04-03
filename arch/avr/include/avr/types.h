/****************************************************************************
 * arch/avr/include/avr/types.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/* This file should never be included directly but, rather, only indirectly
 * through stdint.h
 */

#ifndef __ARCH_AVR_INCLUDE_AVR_TYPES_H
#define __ARCH_AVR_INCLUDE_AVR_TYPES_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Type Declarations
 ****************************************************************************/

#ifndef __ASSEMBLY__

/* These are the sizes of the standard integer types.  NOTE that these type
 * names have a leading underscore character.  This file will be included
 * (indirectly) by include/stdint.h and typedef'ed to the final name without
 * the underscore character.  This roundabout way of doings things allows
 * the stdint.h to be removed from the include/ directory in the event that
 * the user prefers to use the definitions provided by their toolchain header
 * files
 */

typedef signed char        _int8_t;    /* char is 8-bits */
typedef unsigned char      _uint8_t;

typedef signed int         _int16_t;   /* int is 16-bits */
typedef unsigned int       _uint16_t;

typedef signed long        _int32_t;  /* long is 32-bits */
typedef unsigned long      _uint32_t;

typedef signed long long   _int64_t;   /* long long is 64-bits */
typedef unsigned long long _uint64_t;

typedef double double_t;

#define __INT64_DEFINED

typedef _int64_t           _intmax_t;
typedef _uint64_t          _uintmax_t;

/* A (near) size is 2 bytes */

#if defined(__SIZE_TYPE__)
/* If __SIZE_TYPE__ is defined we define ssize_t based on size_t.
 * We simply change "unsigned" to "signed" for this single definition
 * to make sure ssize_t and size_t only differ by their signedness.
 */

#define unsigned signed
typedef __SIZE_TYPE__      _ssize_t;
#undef unsigned
typedef __SIZE_TYPE__      _size_t;
#else
typedef signed int         _ssize_t;
typedef unsigned int       _size_t;
#endif

/* A FAR pointer is 4 bytes */

typedef signed long        _int_farptr_t;
typedef unsigned long      _uint_farptr_t;

/* This is the size of the interrupt state save returned by up_irq_save(). */

typedef unsigned char      irqstate_t;

#endif /* __ASSEMBLY__ */

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#endif /* __ARCH_AVR_INCLUDE_AVR_TYPES_H */
