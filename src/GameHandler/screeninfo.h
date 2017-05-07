#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "../GameObjects/gameobject.h"
#include "../GameObjects/guiobject.h"

typedef struct{
	void (*update)(GameObject *gameObjects, GUIObject *guiObjects, void *uniqueValues);
	void (*initialize)(GameObject *gameObjects, GUIObject *guiObjects, void *uniqueValues);
	void *uniqueValues;
} ScreenInfo;

ScreenInfo *createScreenInfo(
	void (*func)(GameObject *gameObjects, GUIObject *guiObjects),
	void (*initialize)(GameObject *gameObjects, GUIObject *guiObjects),
	void *uniqueValues);

int si_update(ScreenInfo *si, GameObject *gameObjects, GUIObject *guiObjects);
void si_initialize(ScreenInfo *si, GameObject *gameObjects, GUIObject *guiObjects);
void si_destroy(ScreenInfo *si);

#endif