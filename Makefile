FLAGS = -Wall -Wextra -Wpedantic -Werror -Os -std=c99

genlicense: genlicense.c
	cc genlicense.c $(FLAGS) -o genlicense

install: genlicense
	mv genlicense /usr/bin

clean:
	rm genlicense
