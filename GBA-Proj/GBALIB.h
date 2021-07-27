// GBALIB.H
// Revised GBALIB for C++
// By Morgan Evans

#include <iostream.h>

#ifndef _GBALIB_CPP
#define _GBALIB_CPP

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;
typedef char sbyte;
typedef short sword;
typedef long sdword;

#define RGB(r,g,b)      ((r & 31) + ((g & 31) << 5) + ((b & 31) << 10))

class GBA_Palette {
  private:
    volatile word* pointer;
    word next_index;
    word colours;
    
  public:
    GBA_Palette();
    GBA_Palette(word _colours, volatile word* _pointer);
    void AddEntry(byte _red, byte _green, byte _blue);
    void AddEntry(byte _index, byte _red, byte _green, byte _blue);
    word GetEntry(byte _index);
};

class GBA_Display {
  private:
    GBA_Palette BG_Palette;
    GBA_Palette OBJ_Palette;
    volatile dword* REG_DISPCNT;
    
  public:
    GBA_Display();
    GBA_Display(word _mode);
    
};
#endif
