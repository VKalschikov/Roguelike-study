#include "screeninfo.h"
#include <stdlib.h>

ScreenInfo *createScreenInfo(
	void (*func)(GameObject *gameObjects, GUIObject *guiObjects, void *uniqueValues),
	void (*init)(GameObject *gameObjects, GUIObject *guiObjects, void *uniqueValues),
	void *uniqueValues)
{
	ScreenInfo *si = (ScreenInfo*)malloc(sizeof(ScreenInfo));
	si->update = func;
	si->initialize = init;;
	si->uniqueValues = uniqueValues;
	return si;
}

int si_update(ScreenInfo *si, GameObject *gameObjects, GUIObject *guiObjects)
{
	return si->update(gameObjects, guiObjects, si->uniqueValues);
}
void si_initialize(ScreenInfo *si, GameObject *gameObjects, GUIObject *guiObjects)
{
	si->initialize(gameObjects, guiObjects, si->uniqueValues);
}

void si_destroy(ScreenInfo *si)
{
	free (si);
}