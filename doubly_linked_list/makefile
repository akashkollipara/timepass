default:
	make all -j4

CFLAGS	:= -Werror -Wall

all: main.elf

.PHONY: clean main.elf
main.elf: out/main.o out/driver.o out/a.o out/b.o
	$(CC) $(CFLAGS) -I ./ $^ -o $@

out/%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
	rm -rf *.o *.elf out/
