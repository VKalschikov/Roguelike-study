#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "screen.h"
#include "../GameObjects/gameobjectsinfo.h"
#include "../enums.h"

typedef struct{
 	int numbersOfScreens;
 	int currentScreen;
	Screen **screens;
	GameObjectsInfo *goinfo;
} GameHandler;

GameHandler *createGameHandler(int numbersOfScreens, int currentScreen, Screen **screens, GameObjectsInfo *goinfo);
void gh_gameCycle(GameHandler *gh, GameObjectsInfo *goinfo,	Event gameEvent);
void gh_refreshCurrentScreen(GameHandler *gh, GameObjectsInfo *goinfo);
void gh_changeCurrentScreen(GameHandler *gh, int screen);
void gh_changeCurrentScreenR(GameHandler *gh, int screen, GameObjectsInfo *goinfo);
void gh_destroy(GameHandler *gh);

#endif 