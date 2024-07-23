/****************************************************************************
 * arch/arm/src/xmc4/xmc4_ecat.h
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

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: xmc4_ecat_initialize
 *
 * Description:
 *   Initialize the EtherCAT module. Configure the pins, the PLL, the
 *   physical ports and run the start up sequence.
 *   See chapter "16.14 Initialization and System Dependencies" from
 *   Infineon-ReferenceManual_XMC4700_XMC4800-UM-v01_03-EN.pdf for
 *   references.
 *
 ****************************************************************************/

void xmc4_ecat_initialize(void);

/****************************************************************************
 * Name: xmc4_ecat_initialize_port_control
 *
 * Description:
 *   Apply the proper physical port configuration based on the pin properties
 *   defined in board.h according to "26.10.1 Port I/O Function Table" from
 *   Infineon-ReferenceManual_XMC4700_XMC4800-UM-v01_03-EN.pdf.
 *
 ****************************************************************************/

void xmc4_ecat_initialize_port_control(void);
