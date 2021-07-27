# Project: LilGuy
# Makefile created by Dev-C++ 4.9.6.0

CC   = C:\devkitadv\bin\gcc.exe
OBJ  = lilguy.o
LIBS =  -L"C:/devkitadv/lib/gcc-lib/arm-agb-elf/3.0.2/interwork" -L"C:/devkitadv/lib/gcc-lib/arm-agb-elf/3.0.2" 
INCS =  -I"C:/devkitadv/include/g++-v3/arm-agb-elf"  -I"C:/devkitadv/arm-agb-elf/include" 
BIN  = LilGuy.bin
CFLAGS = $(INCS)  -s

.PHONY: all all-before all-after clean clean-custom

all: all-before LilGuy.bin all-after


clean: clean-custom
	rm -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o "LilGuy.bin" $(LIBS) $(CFLAGS)

lilguy.o: lilguy.c
	$(CC) -c lilguy.c -o lilguy.o $(CFLAGS)
