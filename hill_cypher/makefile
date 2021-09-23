default: all

CFLAGS	:= -Werror -Wall

all: main.elf

.PHONY: clean main.elf
main.elf: out/hill.o out/lin_mat_ops.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

.SECONDEXPANSION:
out/%.o: src/%.c | $$(@D)/
	$(CC) $(CFLAGS) -c $< -o $@

out/:
	mkdir -p $(@D)

clean:
	rm -rf *.o *.elf out/
