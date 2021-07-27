/*  GBALIB.H
    GBA Library Header
    Contains various predefined macros for easier access of GBA functions
    By Morgan Evans
    
    1.00 (03-07-2002) - First hour on the job :)
                        Created typedefs for simple data types and macros
                        for simple video work only.
         (04-07-2002) - Added memory pointer for OAM
                        Created data structure for Sprite Object Attributes 
*/

#ifndef GBALIB_HDR
#define GBALIB_HDR

// A few typesdefs to make working with bytes and words easier
typedef unsigned char byte;
typedef char sbyte;
typedef unsigned short word;
typedef short sword;
typedef unsigned long dword;
typedef long sdword;

// Pointers to specific memory addresses
#define VideoBuffer     ((volatile word*)   0x6000000)                     // Displayed image memory pointer
#define BackBuffer      ((volatile word*)   0x600A000)                     // Back-buffer memory pointer
#define BGPalette       ((volatile word*)   0x5000000)                     // Background palette memory pointer
#define OBJPalette      ((volatile word*)   0x5000200)                     // Sprite palette memory pointer
#define OBJAttributes   ((volatile word*)   0x7000000)

// Registers
#define REG_VCount      (*(volatile word*)  0x4000006)                     // Gives the count of lines plotted
#define REG_DispCnt     (*(volatile dword*) 0x4000000)                     // Display control register

// Some display constants
#define TILED_MODE0     0x0                                                // Allows access to all backgrounds
#define TILED_MODE1     0x1                                                // Allows access to backgrouns 0,1 and 2 (which has rotate / scaling capabilities)
#define TILED_MODE2     0x2                                                // Allows access to backgrounds 2 and 3 with rotate / scaling
#define SINGLE_BUFFER16 0x3                                                // Single buffered 16 bit display mode
#define DOUBLE_BUFFER8  0x4                                                // Double buffered 8->16 bit paletted mode (240 x 160)
#define DOUBLE_BUFFER16 0x5                                                // Double buffered 16 bit mode (160 x 128)
#define USE_BACK_BUFFER 0x10
#define OBJ_MAP_2D      0x0
#define OBJ_MAP_1D      0x40
#define FORCE_BLANK     0x80
#define ENABLE_BG0      0x100
#define ENABLE_BG1      0x200
#define ENABLE_BG2      0x400
#define ENABLE_BG3      0x800
#define ENABLE_SPRITES  0x1000

#define RGB(r,g,b)      ((r & 31) + ((g & 31) << 5) + ((b & 31) << 10))    // Macro allowing definition of 16 bit BGR value

// OAM Data structure
struct tagOAMentry {
    word attr0;                                                            // Y-coord (bits 0-7), scale & rotate (8), double size (9), alpha blending (10-11), mozaic (12), palettes (13), shape(14-15)
    word attr1;                                                            // X-coord (bits 0-8), scale & roate (9 - 11), x/y flip (12-13), shape (14-15)
    word attr2;                                                            // Character number (bits 0-9), priority (10-11), palette selection (12-15)
    word attr3;                                                            // Rotation and scaling (will define in next revision).
};



#endif
