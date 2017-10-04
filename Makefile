CC = gcc

life: Life.c
	$(CC) -Wall -ansi --pedantic Life.c src/Draw.o -lpng -o Life

partial: src/Input.c src/Draw.c src/Simulation.c
	$(CC) -c src/Input.c -c src/Draw.c -c src/Simulation.c
clean:
	rm pictures/D*
