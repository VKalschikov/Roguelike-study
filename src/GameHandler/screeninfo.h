#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "../GameObjects/gameobject.h"
#include "../GameObjects/guiobject.h"

typedef struct{
	void (*update)(GameObject *gameObjects, GUIObject *guiObjects);
} ScreenInfo;

ScreenInfo *createScreenInfo(void (*func)(GameObject *gameObjects, GUIObject *guiObjects));
void si_destroy(ScreenInfo *si);

#endif