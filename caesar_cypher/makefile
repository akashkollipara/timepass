default: all

CFLAGS	:= -Werror -Wall

all: main.elf

.PHONY: clean main.elf
main.elf: out/caesar.o
	$(CC) $(CFLAGS) $^ -o $@

.SECONDEXPANSION:
out/%.o: src/%.c | $$(@D)/
	$(CC) $(CFLAGS) -c $< -o $@

out/:
	mkdir -p $(@D)

clean:
	rm -rf *.o *.elf out/
