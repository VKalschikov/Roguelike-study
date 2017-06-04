#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "screeninfo.h"

#include "../vectors.h"
#include "../enums.h"

typedef struct{
	ScreenInfo *screenInfo;
} Controller;

Controller *createController(ScreenInfo *si);

void c_initialize(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects);

int c_update(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects,
	Event gameEvent);

void c_destroy(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects
);

#endif  