#ifndef SCREEN_H
#define SCREEN_H

#include "controller.h"
#include "screeninfo.h"

#include "../GameObjects/Vectors/gameobjectsvector.h"
#include "../GameObjects/Vectors/guiobjectsvector.h"

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
	GUIObjectsVector *guiObjects);

void s_destroy(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects);

#endif 