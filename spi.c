#include "spi.h"
#include <stdint.h>

void spi_tx(spi_ctrl* spictrl, uint8_t in)
{
#if __riscv_atomic
  int32_t r;
  do {
    asm volatile (
      "amoor.w %0, %2, %1\n"
      : "=r" (r), "+A" (spictrl->txdata.raw_bits)
      : "r" (in)
    );
  } while (r < 0);
#else
  while ((int32_t) spictrl->txdata.raw_bits < 0);
  spictrl->txdata.data = in;
#endif
}
