#include "screeninfo.h"
#include <stdlib.h>

ScreenInfo *createScreenInfo(void (*func)(GameObject *gameObjects, GUIObject *guiObjects))
{
	ScreenInfo *si = (ScreenInfo*)malloc(sizeof(ScreenInfo));
	si->update = func;
	return si;
}

void si_destroy(ScreenInfo *si)
{
	free (si);
}