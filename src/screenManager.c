#include <stdlib.h>
#include "screenManager.h"
#include "screen.h"

ScreenManager *sm_createScreenManager(Screen *screen, void *game)
{
	ScreenManager *s = (ScreenManager*)malloc(sizeof(ScreenManager));
	s->currentScreen = screen;
	s->game = game;
	return s;
}

void sm_changeCurrentScreenD(ScreenManager *s, Screen *screen)
{

	free(s->currentScreen);
	sm_changeCurrentScreen(s,screen);
}

void sm_changeCurrentScreen(ScreenManager *s, Screen *screen)
{
	s->currentScreen = screen;
}

void sm_drawCurrentScreen(ScreenManager *s)
{
	s->currentScreen->draw(s->game);
}

Screen *sm_getCurrentScreen(ScreenManager *s)
{
	return s->currentScreen;
}

void sm_destroyD(ScreenManager *s)
{
	free(s->currentScreen);
	sm_destroy(s);
}

void sm_destroy(ScreenManager *s)
{
	free(s);
}