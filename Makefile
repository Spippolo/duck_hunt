L_OPTS=`pkg-config --libs sdl2 SDL2_image`
C_OPTS=`pkg-config --cflags sdl2 SDL2_image`
CC=gcc

all: main.o window.o event.o
	$(CC) $(L_OPTS) -lm main.o window.o event.o -o main.out

main.o: src/main.c
	$(CC) -c $(C_OPTS) src/main.c

window.o: src/ui/window.c
	$(CC) -c $(C_OPTS) src/ui/window.c

event.o: src/event.c
	$(CC) -c $(C_OPTS) src/event.c

clean:
	rm *.o *.out
