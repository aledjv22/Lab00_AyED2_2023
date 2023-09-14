.PHONY: all clean run_tictactoe run_bounds

CFLAGS = -Wall -Wextra -pedantic -std=c99

all: tateti bounds

tateti: tictactoe.c
	gcc $(CFLAGS) tictactoe.c -o tateti

bounds: bounds.c
	gcc $(CFLAGS) bounds.c -o bounds

run_tictactoe: tateti
	./tateti

run_bounds: bounds
	./bounds

clean:
	rm -f tateti bounds