# Test Code makefile

SHEELL		:= /bin/sh
N_THREADS	:= $(shell grep -c ^processor /proc/cpuinfo)

SRCS		:= $(notdir $(wildcard *.c))
OBJS		:= $(addprefix out/,$(SRCS:.c=.o))

INCLUDE		+= -I ./
CFLAGS		+= -Werror -Wall	\
		   $(INCLUDE)		\
		   -Os			\
		   -ffunction-sections	\
		   -fdata-sections

ELF		:= out/test.elf

default:
	make all -j $(N_THREADS)

.PHONY: all $(ELF) $(OBJS) --out clean run

all	: |--out $(ELF)

$(ELF)	: $(OBJS)
	echo "Generating $(notdir $@) ..."
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS)	: out/%.o: %.c
	echo "Compiling $(subst .o,.c,$(notdir $@)) ..."
	$(CC) $(CFLAGS) -c $< -o $@

--out	:
	mkdir -p out/

clean	:
	rm -rf out/

run	:
	out/test.elf

.SILENT:
