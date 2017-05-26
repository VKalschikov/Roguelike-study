#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../vectors.h"
#include "screeninfo.h"

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
	GUIObjectsVector *guiObjects);

void c_destroy(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects
);

#endif  