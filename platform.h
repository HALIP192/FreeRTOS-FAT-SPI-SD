#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "riscv-virt.h"

#ifdef __ASSEMBLER__
#define _AC(X,Y)  X
#else
#define _AC(X,Y) (X##Y)
#endif

#define _REG32(p, i) (*(volatile uint32_t *) ((p) + (i)))

#define UART_REG_TXFIFO 0x00
#define UART0_CTRL_ADDR _AC(0x10010000,UL)
#define UART0_REG(offset) _REG32(UART0_CTRL_ADDR, offset)

#define SPI_CTRL_ADDR _AC(0x10050000,UL)
#define SPI_CTRL_SIZE _AC(0x1000,UL)
#define SPI_MEM_ADDR  _AC(0x20000000,UL)
#define SPI_MEM_SIZE  _AC(0x10000000,UL)

#define SPI_CSMODE_AUTO         0
#define SPI_CSMODE_HOLD         2
#define SPI_CSMODE_OFF          3

#define SPI_DIR_RX              0
#define SPI_DIR_TX              1

#define SPI_PROTO_S             0
#define SPI_PROTO_D             1
#define SPI_PROTO_Q             2

#define SPI_ENDIAN_MSB          0
#define SPI_ENDIAN_LSB          1


#define RTC_PERIOD_NS _AC(1000,UL)


#define CLINT_CTRL_ADDR _AC(0x2000000,UL)
#define CLINT_REG(offset) _REG32(CLINT_CTRL_ADDR, offset)


#endif
