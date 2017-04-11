#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "screen.h"

typedef struct {
	void *game;
	Screen *currentScreen;
} ScreenManager;

ScreenManager *sm_createScreenManager(Screen *Screen, void *game);

void sm_changeCurrentScreenD(ScreenManager *s, Screen *Screen);

void sm_changeCurrentScreen(ScreenManager *s, Screen *Screen);

void sm_drawCurrentScreen(ScreenManager *s);

Screen *sm_getCurrentScreen(ScreenManager *s);

void sm_destroy(ScreenManager *s);

void sm_destroyD(ScreenManager *s);

#endif