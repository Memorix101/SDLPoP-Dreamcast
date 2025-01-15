#
# Memorix101
# Copyright (C) 2024
#   

TARGET = pop.elf
HFILES = common.h config.h data.h proto.h types.h
OBJS = stb_vorbis.o main.o data.o seg000.o seg001.o seg002.o seg003.o seg004.o seg005.o seg006.o seg007.o seg008.o seg009.o seqtbl.o replay.o options.o lighting.o screenshot.o menu.o midi.o opl3.o romdisk.o
#OBJS = stb_vorbis_ac.o main_stb.o romdisk.o
KOS_ROMDISK_DIR = romdisk

KOS_CFLAGS += -I/opt/toolchains/dc/kos/include -I/opt/toolchains/dc/kos/addons/include -I$(KOS_BASE)/kernel/arch/dreamcast/include/dc -DDISABLE_SNPRINTF_CHECKS -DDREAMCAST -fno-exceptions -O3 -ffunction-sections -fdata-sections
KOS_CPPFLAGS += -fexceptions -std=c++17 -fpermissive -O2

# Update library paths and libraries for SDL2
KOS_LIBS+= -L./tools -L/opt/toolchains/dc/kos/addons/lib/dreamcast

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean: rm-elf
	-rm -f $(OBJS)

rm-elf:
	-rm -f $(TARGET) pop.elf sdl2_pop-dc.cdi romdisk.*

$(TARGET): $(OBJS) $(HFILES)
	kos-c++ -o $(TARGET) $(OBJS) $(OBJEXTRA) $(KOS_CFLAGS) -lwav -lSDL2_image -lSDL2 -lSDL2main -lGL -lpng -ljpeg -lz -lkosutils $(KOS_LIBS) -fno-exceptions -fno-rtti -Wl,--gc-sections
	./make_cdi.sh

run: $(TARGET) 
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk.img
	$(KOS_STRIP) $(TARGET)

