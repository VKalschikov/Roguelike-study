#include <stdlib.h>
#include <stdio.h>

#include "controller.h"
#include "screeninfo.h"

#include "../vectors.h"
#include "../enums.h"

Controller *createController(ScreenInfo *si)
{
	printf("Create Controller\n");
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
	printf("Initialize Controller\n");
	si_initialize(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects);
}

int c_update(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects,
	Event gameEvent)
{
	printf("Update Controller\n");
	return si_update(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects, gameEvent);
}

void c_destroy(
	Controller *controller,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects
)
{
	printf("Destroy Controller\n");
	si_destroy(controller->screenInfo, staticGameObjects, dynamicGameObjects, guiObjects);
	free (controller);
}