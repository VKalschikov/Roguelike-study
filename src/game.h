#ifndef GAME_H
#define GAME_H

#include "screenManager.h"

typedef struct {
	enum State{PLAY = 0, FINISHED = 1} state;
	ScreenManager *screenManager;
} Game;

Game *g_createGame();

void g_changeScreenD(Game *game, Screen *screen);

void g_changeScreen(Game *game, Screen *screen);

void g_drawScreen(Game *game);

ScreenManager *g_getScreenManager(Game *game);

void g_setScreenManager(Game *game, ScreenManager *sm);

int g_getState(Game *game);

void g_setState(Game *game, int state);

void g_destroy(Game *g);

#endif