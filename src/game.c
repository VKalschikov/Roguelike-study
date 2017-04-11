#include <stdlib.h>
#include "game.h"
#include "screenManager.h"

Game *g_createGame()
{
	Game *g = (Game*)malloc(sizeof(Game));
	g->screenManager = sm_createScreenManager(NULL, g);
	return g;
}

void g_changeScreenD(Game *game, Screen *screen)
{
	sm_changeCurrentScreenD(g_getScreenManager(game), screen);
}

void g_changeScreen(Game *game, Screen *screen)
{
	sm_changeCurrentScreen(g_getScreenManager(game), screen);
}

void g_drawScreen(Game *game)
{
	sm_drawCurrentScreen(g_getScreenManager(game));
}

ScreenManager *g_getScreenManager(Game *game)
{
	return game->screenManager;
}

void g_setScreenManager(Game *game, ScreenManager *sm)
{
	game->screenManager = sm;
}

int g_getState(Game *game)
{
	return game->state;
}

void g_setState(Game *game, int state)
{
	game->state = state;
}

void g_destroy(Game *g)
{
	sm_destroyD(g->screenManager);
	free(g);
}

