#include <stdlib.h>
#include "screen.h"

#include "gamehandler.h"
#include "../GameObjects/gameobjectsinfo.h"

GameHandler *createGameHandler(int numbersOfScreens, int currentScreen, Screen **screens, GameObjectsInfo *goinfo)
{
	GameHandler *gh = (GameHandler*)malloc(sizeof(GameHandler));
	gh->numbersOfScreens = numbersOfScreens;
	gh->screens = screens;
	gh->currentScreen = currentScreen;
	gh_refreshCurrentScreen(gh, goinfo);
	return gh;
}

void gh_gameCycle(GameHandler *gh, GameObjectsInfo *goinfo)
{
	int screenChanger = s_update(
		gh->screens[gh->currentScreen],
		goinfo->staticGameObjects[gh->currentScreen],
		goinfo->dynamicGameObjects[gh->currentScreen],
		goinfo->GUIObjects[gh->currentScreen] 
	);

	if(screenChanger!=0)
	{
		if(screenChanger>0)
		{
			gh_changeCurrentScreen(gh, screenChanger);
		}
		else
		{
			gh_changeCurrentScreenR(gh, screenChanger*-1, goinfo);
		}
	}
}

void gh_refreshCurrentScreen(GameHandler *gh, GameObjectsInfo *goinfo)
{
	s_initialize(		
		gh->screens[gh->currentScreen],
		goinfo->staticGameObjects[gh->currentScreen],
		goinfo->dynamicGameObjects[gh->currentScreen],
		goinfo->GUIObjects[gh->currentScreen]
	);
}

void gh_changeCurrentScreen(GameHandler *gh, int screen)
{
	gh->currentScreen = screen;
}

void gh_changeCurrentScreenR(GameHandler *gh, int screen, GameObjectsInfo *goinfo)
{
	gh_refreshCurrentScreen(gh, goinfo);
	gh_changeCurrentScreen(gh, screen);
}

void gh_destroy(GameHandler *gh)
{
	free(gh);
}