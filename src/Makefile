#
# Memorix101
# Copyright (C) 2024
#   

TARGET = PoP.elf
HFILES = common.h config.h data.h proto.h types.h
OBJS = stb_vorbis.o main.o data.o seg000.o seg001.o seg002.o seg003.o seg004.o seg005.o seg006.o seg007.o seg008.o seg009.o seqtbl.o replay.o options.o lighting.o screenshot.o menu.o midi.o opl3.o romdisk.o
#OBJS = mixer_ogg.o celeste.o sdl20compat.inc.o sdl12main.o romdisk.o
KOS_ROMDISK_DIR = romdisk

KOS_CFLAGS += -I../lmikmod/include -I/opt/toolchains/dc/kos/include -I/opt/toolchains/dc/kos/addons/include -I../supertux-dc-SDL_dreamhal-Fakemixer/ports/mikmod/lmikmod/include \
-I$(KOS_BASE)/kernel/arch/dreamcast/include/dc -DDREAMCAST -D_USE_MATH_DEFINES -D_THREAD_SAFE -DOSX

KOS_CPPFLAGS += -fexceptions -std=c++11 -fpermissive -O2

# Update library paths and libraries for SDL2
KOS_LIBS+= -L./tools -L/opt/toolchains/dc/kos/addons/lib/dreamcast

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean: rm-elf
	-rm -f $(OBJS)

rm-elf:
	-rm -f $(TARGET) PoP-dc.cdi romdisk.*

$(TARGET): $(OBJS) $(HFILES)
	kos-cc -o $(TARGET) $(OBJS) $(OBJEXTRA) -ltremor -lkosfat -lm -lSDL2_image -lSDL2 -lSDL2main -lGL -lkosutils $(KOS_LIBS) -fno-exceptions -fno-rtti
	./make_cdi.sh

run: $(TARGET) 
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk.img
	$(KOS_STRIP) $(TARGET)

