/****************************************************************************
 * arch/risc-v/src/esp32c6/hardware/esp32c6_soc.h
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_RISCV_SRC_ESP32C6_HARDWARE_ESP32C6_SOC_H
#define __ARCH_RISCV_SRC_ESP32C6_HARDWARE_ESP32C6_SOC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>
#include <stdbool.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define DR_REG_PLIC_MX_BASE                     0x20001000
#define DR_REG_PLIC_UX_BASE                     0x20001400
#define DR_REG_CLINT_M_BASE                     0x20001800
#define DR_REG_CLINT_U_BASE                     0x20001C00

#define DR_REG_UART_BASE                        0x60000000
#define DR_REG_UART1_BASE                       0x60001000
#define DR_REG_SPI0_BASE                        0x60002000
#define DR_REG_SPI1_BASE                        0x60003000
#define DR_REG_I2C_EXT_BASE                     0x60004000
#define DR_REG_UHCI0_BASE                       0x60005000
#define DR_REG_RMT_BASE                         0x60006000
#define DR_REG_LEDC_BASE                        0x60007000
#define DR_REG_TIMERGROUP0_BASE                 0x60008000
#define DR_REG_TIMERGROUP1_BASE                 0x60009000
#define DR_REG_SYSTIMER_BASE                    0x6000A000
#define DR_REG_TWAI0_BASE                       0x6000B000
#define DR_REG_I2S_BASE                         0x6000C000
#define DR_REG_TWAI1_BASE                       0x6000D000
#define DR_REG_APB_SARADC_BASE                  0x6000E000
#define DR_REG_USB_SERIAL_JTAG_BASE             0x6000F000
#define DR_REG_INTERRUPT_MATRIX_BASE            0x60010000
#define DR_REG_ATOMIC_BASE                      0x60011000
#define DR_REG_PCNT_BASE                        0x60012000
#define DR_REG_SOC_ETM_BASE                     0x60013000
#define DR_REG_MCPWM_BASE                       0x60014000
#define DR_REG_PARL_IO_BASE                     0x60015000
#define DR_REG_HINF_BASE                        0x60016000
#define DR_REG_SLC_BASE                         0x60017000
#define DR_REG_SLCHOST_BASE                     0x60018000
#define DR_REG_PVT_MONITOR_BASE                 0x60019000
#define DR_REG_GDMA_BASE                        0x60080000
#define DR_REG_SPI2_BASE                        0x60081000
#define DR_REG_AES_BASE                         0x60088000
#define DR_REG_SHA_BASE                         0x60089000
#define DR_REG_RSA_BASE                         0x6008A000
#define DR_REG_ECC_MULT_BASE                    0x6008B000
#define DR_REG_DS_BASE                          0x6008C000
#define DR_REG_HMAC_BASE                        0x6008D000
#define DR_REG_IO_MUX_BASE                      0x60090000
#define DR_REG_GPIO_BASE                        0x60091000
#define DR_REG_GPIO_EXT_BASE                    0x60091f00 //ESP32C6-TODO
#define DR_REG_MEM_MONITOR_BASE                 0x60092000
#define DR_REG_PAU_BASE                         0x60093000
#define DR_REG_HP_SYSTEM_BASE                   0x60095000
#define DR_REG_PCR_BASE                         0x60096000
#define DR_REG_TEE_BASE                         0x60098000
#define DR_REG_HP_APM_BASE                      0x60099000
#define DR_REG_LP_APM0_BASE                     0x60099800
#define DR_REG_MISC_BASE                        0x6009F000

#define DR_REG_PMU_BASE                         0x600B0000
#define DR_REG_LP_CLKRST_BASE                   0x600B0400
#define DR_REG_EFUSE_BASE                       0x600B0800
#define DR_REG_LP_TIMER_BASE                    0x600B0C00
#define DR_REG_LP_AON_BASE                      0x600B1000
#define DR_REG_LP_UART_BASE                     0x600B1400
#define DR_REG_LP_I2C_BASE                      0x600B1800
#define DR_REG_LP_WDT_BASE                      0x600B1C00
#define DR_REG_LP_IO_BASE                       0x600B2000
#define DR_REG_LP_I2C_ANA_MST_BASE              0x600B2400
#define DR_REG_LPPERI_BASE                      0x600B2800
#define DR_REG_LP_ANALOG_PERI_BASE              0x600B2C00
#define DR_REG_LP_TEE_BASE                      0x600B3400
#define DR_REG_LP_APM_BASE                      0x600B3800
#define DR_REG_OPT_DEBUG_BASE                   0x600B3C00

#define DR_REG_TRACE_BASE                       0x600C0000
#define DR_REG_ASSIST_DEBUG_BASE                0x600C2000
#define DR_REG_CPU_BUS_MONITOR_BASE             0x600C2000
#define DR_REG_INTPRI_BASE                      0x600C5000
#define DR_REG_EXTMEM_BASE                      0x600C8000

/* Registers Operation */

#define REG_UHCI_BASE(i)      (DR_REG_UHCI0_BASE - (i) * 0x8000)
#define REG_UART_BASE(i)      (DR_REG_UART_BASE + (i) * 0x1000)
#define REG_UART_AHB_BASE(i)  (DR_REG_UART_BASE + (i) * 0x10000)
#define UART_FIFO_AHB_REG(i)  (REG_UART_AHB_BASE(i) + 0x0)
#define REG_I2S_BASE(i)       (DR_REG_I2S_BASE)
#define REG_TIMG_BASE(i)      (DR_REG_TIMERGROUP0_BASE + (i) * 0x1000)
#define REG_SPI_MEM_BASE(i)   (DR_REG_SPI0_BASE + (i) * 0x1000)
#define REG_SPI_BASE(i)       (DR_REG_SPI2_BASE)
#define REG_I2C_BASE(i)       (DR_REG_I2C_EXT_BASE)
#define REG_MCPWM_BASE(i)     (DR_REG_MCPWM_BASE)
#define REG_TWAI_BASE(i)      (DR_REG_TWAI_BASE + (i) * 0x2000)

/* Peripheral Clock */

#define APB_CLK_FREQ_ROM        (40 * 1000000)
#define CPU_CLK_FREQ_ROM        APB_CLK_FREQ_ROM
#define UART_CLK_FREQ_ROM       (40 * 1000000)
#define EFUSE_CLK_FREQ_ROM      (20 * 1000000)
#define CPU_CLK_FREQ            APB_CLK_FREQ
#define APB_CLK_FREQ            (80 * 1000000)
#define REF_CLK_FREQ            (1000000)
#define RTC_CLK_FREQ            (20 * 1000000)
#define XTAL_CLK_FREQ           (40 * 1000000)
#define UART_CLK_FREQ           APB_CLK_FREQ
#define WDT_CLK_FREQ            APB_CLK_FREQ
#define TIMER_CLK_FREQ          (80000000 >> 4) /* 80MHz divided by 16 */
#define SPI_CLK_DIV             4
#define TICKS_PER_US_ROM        40    /* CPU is 80MHz */
#define GPIO_MATRIX_DELAY_NS    0

#define PLIC_MXINT_ENABLE_REG          (DR_REG_PLIC_MX_BASE + 0x0)
#define PLIC_MXINT_TYPE_REG            (DR_REG_PLIC_MX_BASE + 0x4)
#define PLIC_MXINT_CLEAR_REG           (DR_REG_PLIC_MX_BASE + 0x8)
#define PLIC_MXINT_THRESH_REG          (DR_REG_PLIC_MX_BASE + 0x90)
#define PLIC_MXINT0_PRI_REG            (DR_REG_PLIC_MX_BASE + 0x10)

#define INTC_INT_PRIO_REG(n)           (PLIC_MXINT0_PRI_REG + (n)*4)

/* Mapping Peripheral IDs to map register addresses. */

#define CORE_MAP_REGADDR(n)            (DR_REG_INTERRUPT_MATRIX_BASE + ((n) << 2))

#define BIT(nr)                     (1UL << (nr))

/* Extract the field from the register and shift it to avoid wrong reading */

#define REG_MASK(_reg, _field) (((_reg) & (_field##_M)) >> (_field##_S))

/* Helper to place a value in a field */

#define VALUE_TO_FIELD(_value, _field) (((_value) << (_field##_S)) & (_field##_M))

#define MHZ (1000000)

#endif /* __ARCH_RISCV_SRC_ESP32C6_HARDWARE_ESP32C6_SOC_H */
