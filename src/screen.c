#include "screen.h"
#include <stdlib.h>
#include "game.h"

Screen *screen_createScreen(void (*drawFunc)(void *ptr))
{
	Screen *s = (Screen*)malloc(sizeof(Screen));
	s->draw = drawFunc;
	return s;
}