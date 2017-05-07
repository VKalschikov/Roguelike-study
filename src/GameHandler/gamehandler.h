#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "screen.h"
#include "../GameObjects/gamobjectsinfo.h"

typedef struct{
 	int numbersOfScreens;
 	int currentScreen;
	Screen **screens;
	GameObjectsInfo *goinfo;
} GameHandler;

GameHandler *createGameHandler(int numbersOfScreens, int currentScreen, GameObjectsInfo *goinfo);
void gh_gameCycle(GameHandler *gh, GameObjectsInfo *goinfo);
void gh_refreshCurrentScreen(GameHandler *gh);
void gh_changeCurrentScreen(GameHandler *gh, int screen);
void gh_changeCurrentScreenR(GameHandler *gh, int screen);
void gh_destroy(GameHandler *gh);

#endif 