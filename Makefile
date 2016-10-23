# compilation flags for gdb
CROSS_COMPILE ?=~/src/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-
LIBROOT ?=/home/explora26/src/STM32F10x_StdPeriph_Lib_V3.5.0
CFLAGS  = -O0 -g3
ASFLAGS = -g 

# object files
OBJS  = main.o
OBJS += startup_stm32f10x.o system_stm32f10x.o 
OBJS += stm32f10x_gpio.o stm32f10x_rcc.o
OBJS += stm32f10x_i2c.o
OBJS += I2C.o delay.o


# name of executable
ELF=$(notdir $(CURDIR)).elf
MAP_FILE=$(notdir $(CURDIR)).map
BIN_FILE=$(notdir $(CURDIR)).bin

# Tool path (Already on bash path)
#TOOLROOT= <insert as appropriate>

# Tools
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar
AS=$(CROSS_COMPILE)as
OBJCOPY=$(CROSS_COMPILE)objcopy

# Code Paths
DEVICE=$(LIBROOT)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
CORE=$(LIBROOT)/Libraries/CMSIS/CM3/CoreSupport
PERIPH=$(LIBROOT)/Libraries/STM32F10x_StdPeriph_Driver

# Search path for perpheral library
vpath %.c $(CORE)
vpath %.c $(PERIPH)/src
vpath %.c $(DEVICE)

#  Processor specific
#Note: Change the processor type. This defines the Proc. clock in the:
#STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/CMSIS/CM3/Device
#Support/ST/STM32F10x/system_stm32f10x.c file which is eventually included.
#PTYPE = STM32F10X_MD_VL
PTYPE = STM32F10X_MD

#LDSCRIPT = stm32f100.ld
LDSCRIPT = stm32f103.ld

# Compilation Flags
FULLASSERT = -DUSE_FULL_ASSERT 

LDFLAGS+= -T$(LDSCRIPT) -mthumb -mcpu=cortex-m3 -nostartfiles -Wl,-Map=$(MAP_FILE)
CFLAGS+= -mcpu=cortex-m3 -mthumb 
CFLAGS+= -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I.
CFLAGS+= -D$(PTYPE) -DUSE_STDPERIPH_DRIVER $(FULLASSERT)

OBJCOPYFLAGS = -O binary

# Build executable 
$(BIN_FILE) : $(ELF)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(ELF) : $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS) $(LDFLAGS_POST)


# compile and generate dependency info
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF) $(MAP_FILE) $(CLEANOTHER) $(BIN_FILE)

debug: $(ELF)
	arm-none-eabi-gdb $(ELF)


# pull in dependencies
-include $(OBJS:.o=.d)
