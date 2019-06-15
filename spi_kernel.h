#pragma once

#include "dma.h"
#include "spi.h"
#include "tick.h"

//#include <inttypes.h>
//#include <config/sysfs/syscall.h>
#ifndef USE_DMA_TRANSFERS
#define VIRT_TO_BUS(ptr) ((uintptr_t)(ptr) | 0xC0000000U)
#endif