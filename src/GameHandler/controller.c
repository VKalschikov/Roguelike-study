#include <stdlib.h>
#include "controller.h"
#include "screeninfo.h"
#include "../vectors.h"

Controller *createController(ScreenInfo *si)
{
	Controller *cont = (Controller*)malloc(sizeof(Controller));
	cont->screenInfo = si;
	return cont;
}

void c_initialize(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	si_initialize(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects);
}

int c_update(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	return si_update(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects);
}

void c_destroy(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects
)
{
	si_destroy(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects);
	free (controller);
}