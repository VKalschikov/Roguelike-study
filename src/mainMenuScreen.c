#include "mainMenuScreen.h"
#include "gameScreen.h"
#include <stdio.h>
#include "game.h"

void MainMenuScreen(void *game){
	printf("Draw main menu screen\n");
	g_changeScreenD((Game*)game, screen_createScreen(GameScreen));
}