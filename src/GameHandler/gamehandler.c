#include <stdlib.h>
#include "screen.h"

#include "../GameObjects/gamobjectsinfo.h"

GameHandler *createGameHandler(int numbersOfScreens, int currentScreen, Screen **screens, GameObjectsInfo *goinfo)
{
	GameHandler *gh = (GameHandler*)malloc(sizeof(GameHandler));
	gh->numbersOfScreens = numbersOfScreens;
	gh->screens = screens;
	gh->currentScreen = currentScreen;
	gh_refreshCurrentScreen(gh)
	return gh;
}
void gh_gameCycle(GameHandler *gh, GameObjectsInfo *goinfo)
{
	s_update(
		gh->screens[gh->currentScreen],
		goinfo->gameObjects,
		goinfo->guiObjects
	);
}

void gh_refreshCurrentScreen(GameHandler *gh)
{
	s_initialize(
		gh->screens[gh->currentScreen],
		goinfo->gameObjects,
		goinfo->guiObjects
	);
}

void gh_changeCurrentScreen(GameHandler *gh, int screen)
{
	gh->currentScreen = screen;
}

void gh_changeCurrentScreenR(GameHandler *gh, int screen);
{
	gh_changeCurrentScreen(gh, screen);
	gh_refreshCurrentScreen(gh);
}

void gh_destroy(GameHandler *gh)
{
	free(gh);
}
