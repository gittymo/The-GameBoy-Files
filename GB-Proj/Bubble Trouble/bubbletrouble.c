// Bubble Trouble v1.00
// By M.Evans

#include <cgb.h>
#include <gb.h>
#include <asm/gbz80/types.h>

// Global variables
UINT32 score = 0;  // Holds the player's score
UINT8 mapx = 0;    // Scrolling map x co-ordinate
UNIT8 mapy = 26;   // Scrolling map y co-ordinate

// Map Data
