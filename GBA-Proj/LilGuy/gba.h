/*  gba.h
    Gameboy Advance interface header
    version 1.0
    (C)2003 Morgan Evans */

#ifndef _gba_me
#define _gba_me

// Typedefs to help translating documentation into code.
typedef unsigned char byte;
typedef char sbyte;
typedef unsigned short word;
typedef short sword;
typedef unsigned long dword;
typedef long sdword;

// Key (e)xecutable, (r)eadable, (w)ritable

// GBA specific constants
#define GBA_ROM				((volatile dword*) 	0x00000000)				// GBA BIOS (16k,e)
#define GBA_EWRAM 		((volatile word*)		0x02000000)				// External (slower, 16-bit) RAM (256K,e,r,w)
#define GBA_IWRAM			((volatile dword*) 	0x03000000)				// Internal (faster, 32-bit) RAM (32K,e,r,w)
#define GBA_PALETTE		((volatile word*)		0x05000000)				// Palette RAM (16x16 or 1x256 16-bit palette entries) (1k)
#define GBA_VRAM			((volatile word*)		0x06000000)				// VRAM for tiles and frame buffer in bitmap modes (96k)
#define GBA_BBUF			((volatile word*)		0x0600A000)				// Pointer to back buffer in VRAM.
#define GBA_OAM				((volatile dword*)	0x07000000)				// Object attribute memory for tiles/sprites (1k)

// Game cartridge specific constants
#define CART_RAM			((volatile byte*) 	0x0E000000)				// Used for game save data (0-64k)

// Palette macro
#define rgb(r,g,b) (r & 31) | ((g & 31) << 5) | ((b & 31) << 5)

// Constants to use with REG_DISPCNT
#define VID_MODE0	0x0																				// 4 backgrounds, no rotate/scale.
#define VID_MODE1	0x1																				// 3 backgrounds, bg2 rotate/scale.
#define VID_MODE2 0x2																				// 2 backgrounds, bg2+3 rotate/scale.
#define VID_MODE3 0x3																				// 16 bit, non-paletted, 240x160, no VBUF
#define VID_MODE4 0x4																				// 8 bit, palettes, 240x160, VBUF
#define VID_MODE5 0x5																				// 16 bit, non-paletted, 160x128, VBUF																				
#define VID_USEBB 1 << 3																	  // Use Back Buffer
#define VID_FPROC 1 << 4																		// Force processing during BBLANK, prevents flickering when lots of sprites in view.
#define VID_SPR1D 1 << 5																		// Sprites are stored sequentially rather that in a 2D grid.
#define VID_BLANK 1 << 6																		// Force screen to go blank.
#define VID_EBG1  1 << 7																		// Enable BG 1
#define VID_EBG2  1 << 8																		// Enable BG 2
#define VID_EBG3  1 << 9																		// Enable BG 3
#define VID_EBG4  1 << 0xA																	// Enable BG 4
#define VID_EOAM	1 << 0xB																	// Enable OAM sprites
#define VID_EWIN1	1 << 0xC																	// Enable Window 1
#define VID_EWIN2	1 << 0xD																	// Enable Window 2
#define VID_ESPRW 1 << 0xE																	// Enable sprite windows.

#define 

// OAM constants
#define OAM_ROTS	1 << 7																		// Rotate and scale flag
#define OAM_DSZ		1 << 8																		// Double size sprite
#define OAM_STRN	1 << 9																		// Semi-transparent sprite
#define OAM_WIN		2 << 9																		// Obj window.
#define OAM_256C	1 << 0xC
#define OAM_MOSC	1 << 0xB
#define OAM_FLIPX 1 << 0xB
#define OAM_FLIPY 1 << 0xC

// Registers
#define REG_DISPCNT	(*(volatile dword*) 0x04000000)
#define REG_VCOUNT	(*(volatile word*) 0x04000006)
#define REG_BG0CNT	(*(volatile word*) 0x04000008)
#define REG_BG1CNT	(*(volatile word*) 0x0400000A)
#define REG_BG2CNT	(*(volatile word*) 0x0400000C)
#define REG_BG3CNT	(*(volatile word*) 0x0400000E)
#define REG_BG0HO		(*(volatile word*) 0x04000010)				// Horizontal pixel offset for tiled background 0
#define REG_BG0VO		(*(volatile word*) 0x04000012)				// Vertical pixel offset for tiled background 0
#define REG_BG1HO		(*(volatile word*) 0x04000014)				// Supported values 0-1023
#define REG_BG1VO		(*(volatile word*) 0x04000016)
#define REG_BG2HO		(*(volatile word*) 0x04000018)
#define REG_BG2VO		(*(volatile word*) 0x0400001A)
#define REG_BG3HO		(*(volatile word*) 0x0400001C)
#define REG_VG3V0		(*(volatile word*) 0x0400001E)
#endif
