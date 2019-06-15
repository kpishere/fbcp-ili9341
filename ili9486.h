#pragma once

#include "config.h"

// Data specific to the ILI9486 controller
#define DISPLAY_SET_CURSOR_X 0x2A
#define DISPLAY_SET_CURSOR_Y 0x2B
#define DISPLAY_WRITE_PIXELS 0x2C

#ifdef WAVESHARE35B_ILI9486
#include "waveshare35b.h"
#endif

#define DISPLAY_NATIVE_WIDTH 320
#define DISPLAY_NATIVE_HEIGHT 480

// On ILI9486 the display bus commands and data are 16 bits rather than the usual 8 bits that most other controllers have.
// (On ILI9486L however the command width is 8 bits, so they are quite different)
#define DISPLAY_SPI_BUS_IS_16BITS_WIDE

// ILI9486 does not behave well if one sends partial commands, but must finish each command or the command does not apply
#define MUST_SEND_FULL_CURSOR_WINDOW

// needs the Touch and Display CS lines pumped for each 32-bit word that is written, or otherwise it does not process bytes on the bus. (it does send
// return bytes back on the MISO line though even without this, so it does at least do something even without this, but nothing would show up on the screen if this pumping is not done)
#define CHIP_SELECT_LINE_NEEDS_REFRESHING_EACH_32BITS_WRITTEN

void InitILI9486(void);
#define InitSPIDisplay InitILI9486
