#ifndef __SPI_H__
#define __SPI_H__
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

//start spi master mode 0 with 8 bits transactions
// CS  : PA11 (I/O) - Arduino D10
// MOSI: PB5 (AF5)  - Arduino D11
// MISO: PB4 (AF5)  - Arduino D12
// SCK : PB3 (AF5)  - Arduino D13
//
void setupSPI();

//start a transaction (lowering CS)
void beginTransaction();

//ends a transaction (raising CS)
void endTransaction();

//low speed transfer: both writing and reading
uint8_t transfer8(uint8_t val);

//higher speed write transfer (than transfer8)
// * check that TX fifo is not full and send data
void write8(uint8_t val);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
