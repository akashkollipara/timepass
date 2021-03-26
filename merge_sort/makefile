default:
	make all -j4

CFLAGS	:= -Werror -Wall -I inc/

all: main.elf

.PHONY: clean main.elf
main.elf: out/main.o
	$(CC) $(CFLAGS) $^ -o $@

.SECONDEXPANSION:
out/%.o: src/%.c | $$(@D)/
	$(CC) $(CFLAGS) -c $< -o $@

out/:
	mkdir -p $(@D)

clean:
	rm -rf *.o *.elf out/
