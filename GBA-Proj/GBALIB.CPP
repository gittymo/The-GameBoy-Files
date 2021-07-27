// GBALIB.CPP

#include "GBALIB.H"

// GBA Palette class definitions -------------------------------------------------------------------------------------

GBA_Palette::GBA_Palette() {
  pointer = (volatile word*) 0x5000000;
  colours = 256;
  next_index = 0;
} // Creates a new background colour palette with 256 colour entries

GBA_Palette::GBA_Palette(word _colours, volatile word* _pointer) {
  pointer = _pointer;
  colours = _colours;
  next_index = 0;
} // Creates a new colour palette with a user defined size and memory location

void GBA_Palette::AddEntry(byte _red, byte _green, byte _blue) {
  if (next_index < colours) {
    pointer[next_index] = RGB(_red , _green, _blue);
    next_index++;
  }
}

void GBA_Palette::AddEntry(byte _index, byte _red, byte _green, byte _blue) {
  if (_index < colours) {
    pointer[_index] = RGB(_red, _green, _blue);
    next_index = _index + 1;
  }
}

word GBA_Palette::GetEntry(byte _index) {
  if (_index < colours) {
    return pointer[_index];
  }
  return 0;
}

// -------------------------------------------------------------------------------- End of GBA_Palette class defintions

// GBA_Display class definitions---------------------------------------------------------------------------------------

GBA_Display::GBA_Display() {
  // Set up GBA with default mode settings
  REG_DISPCNT = (volatile dword*) 0x4000000;
  *REG_DISPCNT = 0x1F60;  // Enable mode 0, all backgrounds available with OAM sprites enabled and forced hblank.
  
  // Create 256 colour background and object palettes
  
}
