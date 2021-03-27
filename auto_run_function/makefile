SHELL	:= /bin/bash
VERBOSE	?= 0
OUT	?= out
SRCS	:= src
INC	:= inc/
OBJS	:= $(wildcard $(SRCS)/*.c)
OBJS	:= $(addprefix $(OUT)/,$(OBJS:.c=.o))
LD_SRC	:= section.ld
CFLAGS	:= -Werror -Wall -I $(INC) -Os		\
	   -ffunction-sections -fdata-sections
OD	:= objdump
SIZE	:= size

ifeq ($(VERBOSE),0)
.SILENT:
endif

default : $(OUT)/main.elf

run : $(OUT)/main.elf
	chmod +x $(OUT)/main.elf
	$(OUT)/main.elf

$(OUT)/main.elf : $(OBJS) | $(OUT)/
	@echo "Linking $(notdir $@) ..."
	$(CC) $(CFLAGS) $^ -o $@ -T $(LD_SRC) -Wl,--gc-sections
	$(OD) -D $@ > $(subst .elf,.lst,$@)
	$(SIZE) $@

$(OBJS): $(OUT)/%.o : %.c | $(OUT)/$(SRCS)/
	@echo "Compiling $(notdir $<) ..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)/%/ :
	mkdir -p $@

clean :
	rm -rf $(OUT)
