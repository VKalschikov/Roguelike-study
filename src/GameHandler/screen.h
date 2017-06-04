#ifndef SCREEN_H
#define SCREEN_H

#include "controller.h"
#include "screeninfo.h"

#include "../vectors.h"
#include "../enums.h"

typedef struct{
	int numberOfScreen;
	Controller *controller;
} Screen;

Screen *createScreen(ScreenInfo *si, int numberOfScreen);

void s_initialize(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects);

int s_update(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects,
	Event gameEvent);

void s_destroy(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects);


#endif 