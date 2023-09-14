.PHONY: all clean run_tictactoe run_bounds

CFLAGS = -Wall -Wextra -pedantic -std=c99

all: tictactoe bounds

tictactoe: tictactoe.c
	gcc $(CFLAGS) tictactoe.c -o tictactoe

bounds: bounds.c
	gcc $(CFLAGS) bounds.c -o bounds

run_tictactoe: tictactoe
	./tictactoe

run_bounds: bounds
	./bounds

clean:
	rm -f tictactoe bounds