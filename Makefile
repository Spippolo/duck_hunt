L_OPTS=`pkg-config --libs sdl2 SDL2_image`
C_OPTS=`pkg-config --cflags sdl2 SDL2_image`
CC=gcc

ASSETS = \
	assets/images/backgrounds/1.png \
	assets/images/backgrounds/2.png \
	assets/images/backgrounds/3.png \
	assets/images/character/1.png \
	assets/images/character/2.png \
	assets/images/character/3.png \
	assets/images/character/4.png \
	assets/images/character/5.png

all: main.o window.o enemy.o event.o
	$(CC) $(L_OPTS) $(ARGS) -lm main.o window.o enemy.o event.o -o main.out

main.o: src/main.c
	$(CC) -c $(C_OPTS) src/main.c

window.o: src/ui/window.c $(ASSETS)
	$(CC) -c $(C_OPTS) src/ui/window.c

event.o: src/event.c
	$(CC) -c $(C_OPTS) src/event.c

enemy.o: src/ai/enemy.c $(ASSETS)
	$(CC) -c $(C_OPTS) src/ai/enemy.c

clean:
	rm *.o *.out
