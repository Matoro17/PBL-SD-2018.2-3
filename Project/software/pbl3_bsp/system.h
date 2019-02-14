/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'Nios' in SOPC Builder design 'Nios'
 * SOPC Builder design path: C:/Users/gabri/Desktop/PBL3tentativadenovo/Nios.sopcinfo
 *
 * Generated: Wed Feb 13 16:41:18 GMT-03:00 2019
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00010820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x11
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00008020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x11
#define ALT_CPU_NAME "Nios"
#define ALT_CPU_RESET_ADDR 0x00008000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00010820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x11
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00008020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x11
#define NIOS2_RESET_ADDR 0x00008000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_ARBITRO4_0(A,B) __builtin_custom_inii(ALT_CI_ARBITRO4_0_N,(A),(B))
#define ALT_CI_ARBITRO4_0_N 0x1
#define ALT_CI_LCD_0(A,B) __builtin_custom_inii(ALT_CI_LCD_0_N,(A),(B))
#define ALT_CI_LCD_0_N 0x0


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS
#define __ARBITRO4
#define __LCD


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x110b0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x110b0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x110b0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Nios"


/*
 * UART_1 configuration
 *
 */

#define ALT_MODULE_CLASS_UART_1 altera_avalon_uart
#define UART_1_BASE 0x11000
#define UART_1_BAUD 115200
#define UART_1_DATA_BITS 8
#define UART_1_FIXED_BAUD 1
#define UART_1_FREQ 50000000
#define UART_1_IRQ 0
#define UART_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_1_NAME "/dev/UART_1"
#define UART_1_PARITY 'N'
#define UART_1_SIM_CHAR_STREAM ""
#define UART_1_SIM_TRUE_BAUD 0
#define UART_1_SPAN 32
#define UART_1_STOP_BITS 1
#define UART_1_SYNC_REG_DEPTH 2
#define UART_1_TYPE "altera_avalon_uart"
#define UART_1_USE_CTS_RTS 0
#define UART_1_USE_EOP_REGISTER 0


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x110b0
#define JTAG_UART_0_IRQ 1
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * led1 configuration
 *
 */

#define ALT_MODULE_CLASS_led1 altera_avalon_pio
#define LED1_BASE 0x110a0
#define LED1_BIT_CLEARING_EDGE_REGISTER 0
#define LED1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED1_CAPTURE 0
#define LED1_DATA_WIDTH 1
#define LED1_DO_TEST_BENCH_WIRING 0
#define LED1_DRIVEN_SIM_VALUE 0
#define LED1_EDGE_TYPE "NONE"
#define LED1_FREQ 50000000
#define LED1_HAS_IN 0
#define LED1_HAS_OUT 1
#define LED1_HAS_TRI 0
#define LED1_IRQ -1
#define LED1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED1_IRQ_TYPE "NONE"
#define LED1_NAME "/dev/led1"
#define LED1_RESET_VALUE 0
#define LED1_SPAN 16
#define LED1_TYPE "altera_avalon_pio"


/*
 * led2 configuration
 *
 */

#define ALT_MODULE_CLASS_led2 altera_avalon_pio
#define LED2_BASE 0x11080
#define LED2_BIT_CLEARING_EDGE_REGISTER 0
#define LED2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED2_CAPTURE 0
#define LED2_DATA_WIDTH 1
#define LED2_DO_TEST_BENCH_WIRING 0
#define LED2_DRIVEN_SIM_VALUE 0
#define LED2_EDGE_TYPE "NONE"
#define LED2_FREQ 50000000
#define LED2_HAS_IN 0
#define LED2_HAS_OUT 1
#define LED2_HAS_TRI 0
#define LED2_IRQ -1
#define LED2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED2_IRQ_TYPE "NONE"
#define LED2_NAME "/dev/led2"
#define LED2_RESET_VALUE 0
#define LED2_SPAN 16
#define LED2_TYPE "altera_avalon_pio"


/*
 * led3 configuration
 *
 */

#define ALT_MODULE_CLASS_led3 altera_avalon_pio
#define LED3_BASE 0x11070
#define LED3_BIT_CLEARING_EDGE_REGISTER 0
#define LED3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED3_CAPTURE 0
#define LED3_DATA_WIDTH 1
#define LED3_DO_TEST_BENCH_WIRING 0
#define LED3_DRIVEN_SIM_VALUE 0
#define LED3_EDGE_TYPE "NONE"
#define LED3_FREQ 50000000
#define LED3_HAS_IN 0
#define LED3_HAS_OUT 1
#define LED3_HAS_TRI 0
#define LED3_IRQ -1
#define LED3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED3_IRQ_TYPE "NONE"
#define LED3_NAME "/dev/led3"
#define LED3_RESET_VALUE 0
#define LED3_SPAN 16
#define LED3_TYPE "altera_avalon_pio"


/*
 * led4 configuration
 *
 */

#define ALT_MODULE_CLASS_led4 altera_avalon_pio
#define LED4_BASE 0x11060
#define LED4_BIT_CLEARING_EDGE_REGISTER 0
#define LED4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED4_CAPTURE 0
#define LED4_DATA_WIDTH 1
#define LED4_DO_TEST_BENCH_WIRING 0
#define LED4_DRIVEN_SIM_VALUE 0
#define LED4_EDGE_TYPE "NONE"
#define LED4_FREQ 50000000
#define LED4_HAS_IN 0
#define LED4_HAS_OUT 1
#define LED4_HAS_TRI 0
#define LED4_IRQ -1
#define LED4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED4_IRQ_TYPE "NONE"
#define LED4_NAME "/dev/led4"
#define LED4_RESET_VALUE 0
#define LED4_SPAN 16
#define LED4_TYPE "altera_avalon_pio"


/*
 * led5 configuration
 *
 */

#define ALT_MODULE_CLASS_led5 altera_avalon_pio
#define LED5_BASE 0x11050
#define LED5_BIT_CLEARING_EDGE_REGISTER 0
#define LED5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED5_CAPTURE 0
#define LED5_DATA_WIDTH 1
#define LED5_DO_TEST_BENCH_WIRING 0
#define LED5_DRIVEN_SIM_VALUE 0
#define LED5_EDGE_TYPE "NONE"
#define LED5_FREQ 50000000
#define LED5_HAS_IN 0
#define LED5_HAS_OUT 1
#define LED5_HAS_TRI 0
#define LED5_IRQ -1
#define LED5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED5_IRQ_TYPE "NONE"
#define LED5_NAME "/dev/led5"
#define LED5_RESET_VALUE 0
#define LED5_SPAN 16
#define LED5_TYPE "altera_avalon_pio"


/*
 * memory configuration
 *
 */

#define ALT_MODULE_CLASS_memory altera_avalon_onchip_memory2
#define MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define MEMORY_BASE 0x8000
#define MEMORY_CONTENTS_INFO ""
#define MEMORY_DUAL_PORT 0
#define MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define MEMORY_INIT_CONTENTS_FILE "Nios_memory"
#define MEMORY_INIT_MEM_CONTENT 1
#define MEMORY_INSTANCE_ID "NONE"
#define MEMORY_IRQ -1
#define MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEMORY_NAME "/dev/memory"
#define MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define MEMORY_RAM_BLOCK_TYPE "AUTO"
#define MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define MEMORY_SINGLE_CLOCK_OP 0
#define MEMORY_SIZE_MULTIPLE 1
#define MEMORY_SIZE_VALUE 20480
#define MEMORY_SPAN 20480
#define MEMORY_TYPE "altera_avalon_onchip_memory2"
#define MEMORY_WRITABLE 1


/*
 * pushbuton1 configuration
 *
 */

#define ALT_MODULE_CLASS_pushbuton1 altera_avalon_pio
#define PUSHBUTON1_BASE 0x11090
#define PUSHBUTON1_BIT_CLEARING_EDGE_REGISTER 0
#define PUSHBUTON1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTON1_CAPTURE 0
#define PUSHBUTON1_DATA_WIDTH 1
#define PUSHBUTON1_DO_TEST_BENCH_WIRING 0
#define PUSHBUTON1_DRIVEN_SIM_VALUE 0
#define PUSHBUTON1_EDGE_TYPE "NONE"
#define PUSHBUTON1_FREQ 50000000
#define PUSHBUTON1_HAS_IN 1
#define PUSHBUTON1_HAS_OUT 0
#define PUSHBUTON1_HAS_TRI 0
#define PUSHBUTON1_IRQ -1
#define PUSHBUTON1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSHBUTON1_IRQ_TYPE "NONE"
#define PUSHBUTON1_NAME "/dev/pushbuton1"
#define PUSHBUTON1_RESET_VALUE 0
#define PUSHBUTON1_SPAN 16
#define PUSHBUTON1_TYPE "altera_avalon_pio"


/*
 * pushbuton2 configuration
 *
 */

#define ALT_MODULE_CLASS_pushbuton2 altera_avalon_pio
#define PUSHBUTON2_BASE 0x11040
#define PUSHBUTON2_BIT_CLEARING_EDGE_REGISTER 0
#define PUSHBUTON2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTON2_CAPTURE 0
#define PUSHBUTON2_DATA_WIDTH 1
#define PUSHBUTON2_DO_TEST_BENCH_WIRING 0
#define PUSHBUTON2_DRIVEN_SIM_VALUE 0
#define PUSHBUTON2_EDGE_TYPE "NONE"
#define PUSHBUTON2_FREQ 50000000
#define PUSHBUTON2_HAS_IN 1
#define PUSHBUTON2_HAS_OUT 0
#define PUSHBUTON2_HAS_TRI 0
#define PUSHBUTON2_IRQ -1
#define PUSHBUTON2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSHBUTON2_IRQ_TYPE "NONE"
#define PUSHBUTON2_NAME "/dev/pushbuton2"
#define PUSHBUTON2_RESET_VALUE 0
#define PUSHBUTON2_SPAN 16
#define PUSHBUTON2_TYPE "altera_avalon_pio"


/*
 * pushbuton3 configuration
 *
 */

#define ALT_MODULE_CLASS_pushbuton3 altera_avalon_pio
#define PUSHBUTON3_BASE 0x11030
#define PUSHBUTON3_BIT_CLEARING_EDGE_REGISTER 0
#define PUSHBUTON3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTON3_CAPTURE 0
#define PUSHBUTON3_DATA_WIDTH 1
#define PUSHBUTON3_DO_TEST_BENCH_WIRING 0
#define PUSHBUTON3_DRIVEN_SIM_VALUE 0
#define PUSHBUTON3_EDGE_TYPE "NONE"
#define PUSHBUTON3_FREQ 50000000
#define PUSHBUTON3_HAS_IN 1
#define PUSHBUTON3_HAS_OUT 0
#define PUSHBUTON3_HAS_TRI 0
#define PUSHBUTON3_IRQ -1
#define PUSHBUTON3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSHBUTON3_IRQ_TYPE "NONE"
#define PUSHBUTON3_NAME "/dev/pushbuton3"
#define PUSHBUTON3_RESET_VALUE 0
#define PUSHBUTON3_SPAN 16
#define PUSHBUTON3_TYPE "altera_avalon_pio"


/*
 * pushbuton4 configuration
 *
 */

#define ALT_MODULE_CLASS_pushbuton4 altera_avalon_pio
#define PUSHBUTON4_BASE 0x11020
#define PUSHBUTON4_BIT_CLEARING_EDGE_REGISTER 0
#define PUSHBUTON4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTON4_CAPTURE 0
#define PUSHBUTON4_DATA_WIDTH 1
#define PUSHBUTON4_DO_TEST_BENCH_WIRING 0
#define PUSHBUTON4_DRIVEN_SIM_VALUE 0
#define PUSHBUTON4_EDGE_TYPE "NONE"
#define PUSHBUTON4_FREQ 50000000
#define PUSHBUTON4_HAS_IN 1
#define PUSHBUTON4_HAS_OUT 0
#define PUSHBUTON4_HAS_TRI 0
#define PUSHBUTON4_IRQ -1
#define PUSHBUTON4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSHBUTON4_IRQ_TYPE "NONE"
#define PUSHBUTON4_NAME "/dev/pushbuton4"
#define PUSHBUTON4_RESET_VALUE 0
#define PUSHBUTON4_SPAN 16
#define PUSHBUTON4_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
