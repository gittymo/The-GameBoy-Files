PROJ = Pengo

SRC = $(PROJ).dsp

cc = gbamake
cflags = -pc:\arm\bin

$(PROJ)._bin:
	$(cc) $(cflags) $(SRC)

