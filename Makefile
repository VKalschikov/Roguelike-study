path = src/

all: Roguelike clean

Roguelike: main.o gameScreen.o mainMenuScreen.o screen.o screenManager.o game.o
	gcc main.o gameScreen.o mainMenuScreen.o screen.o screenManager.o game.o -o Roguelike -lcsfml-graphics -lcsfml-window -lcsfml-system 

main.o: $(path)main.c
	gcc -c $(path)main.c -std=c99

gameScreen.o: $(path)gameScreen.c
	gcc -c $(path)gameScreen.c -std=c99

mainMenuScreen.o: $(path)mainMenuScreen.c
	gcc -c $(path)mainMenuScreen.c -std=c99

screen.o: $(path)screen.c
	gcc -c $(path)screen.c -std=c99

screenManager.o: $(path)screenManager.c
	gcc -c $(path)screenManager.c -std=c99

game.o: $(path)game.c
	gcc -c $(path)game.c -std=c99

clean:
	rm -rf *.o