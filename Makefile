FLAGS = -Wall -Wextra -Wpedantic -Werror -Os -std=c99

genlicense: genlicense.c
	cc genlicense.c $(FLAGS) -o genlicense

install: genlicense
	cp genlicense /usr/bin
	cp genlicense.1 /usr/local/share/man/man1/

clean:
	rm genlicense
