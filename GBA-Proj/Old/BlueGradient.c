// BlueGradient.C
// Plots a blue gradient across the display
// By Morgan Evans

#include "GBALIB.H"

word* theDisplay = (word*) VideoBuffer;

int main() {
  SetMode(SINGLE_BUFFER16 | ENABLE_BG2);
  int x,y;
  
  for (x = 0; x < 240; x += 1) {
    for (y = 0; y < 160; y += 1) {
      int shade = ((x / 8) + (y / 6)) / 2;
      theDisplay[x + (y * 240)] = RGB(31 - shade,0,shade);
    }
  }
  
  return 0;
}
      

