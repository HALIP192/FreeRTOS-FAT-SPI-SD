#ifndef __SD_H__
#define __SD_H__

#define SD_INIT_ERROR_CMD0 1
#define SD_INIT_ERROR_CMD8 2
#define SD_INIT_ERROR_ACMD41 3
#define SD_INIT_ERROR_CMD58 4
#define SD_INIT_ERROR_CMD16 5

#define SD_COPY_ERROR_CMD18 1
#define SD_COPY_ERROR_CMD18_CRC 2

#ifndef __ASSEMBLER__

#include "spi.h"
#include <stdint.h>
#include <stddef.h>

int sd_init(spi_ctrl* spi, unsigned int input_clk_hz, int skip_sd_init_commands);
int sd_copy(spi_ctrl* spi, void* dst, uint32_t src_lba, size_t size);

#endif /* !__ASSEMBLER__ */

#endif /* __SD_H__ */
