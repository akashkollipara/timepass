# Assignment 1 makefile

SHELL		:= /bin/bash
OUT_DIR		?= out
VERBOSE		?= 0
RELEASE		?= 1

SRC_DIR		:= src
INC_DIR		:= inc
C_OBJS		:= $(SRC_DIR)/main.o $(SRC_DIR)/buffer.o
EXE		:= $(OUT_DIR)/assignment1.elf

CC		:= gcc
OD		:= objdump
OC		:= objcopy
SIZE		:= size

CFLAGS		:= -I $(INC_DIR)	\
		   -Wall -Werror -Wextra\
		   -Os

LIBS		:= -lpthread

ifeq ($(VERBOSE),0)
.SILENT:
endif

ifeq ($(RELEASE),0)
CFLAGS		+= -g
CFLAGS		+= -DDEBUG=1
endif

default: $(EXE)

$(EXE): $(addprefix $(OUT_DIR)/, $(C_OBJS))
	@mkdir -p $(@D)
	@echo "Generating $(@F) ..."
	$(CC) $^ -o $@ $(LIBS)
	$(OD) --disassemble-all -h $@ > $(@:.elf=.lst) 2> /dev/null
	@echo ""
	@echo "Size:"
	@echo "============================================================"
	@cd $(@D); $(SIZE) $(@F) 

$(OUT_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@echo "Compiling $(@F:.o=.c)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)/

run: $(EXE)
	chmod +x $<
	$<
