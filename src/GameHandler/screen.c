#include <stdlib.h>
#include <stdio.h>
#include "screen.h"

#include "controller.h"
#include "screeninfo.h"

#include "../vectors.h"
#include "../enums.h"

Screen *createScreen(ScreenInfo *si, int numberOfScreen)
{
	printf("Create Screen\n");
	Screen *screen = (Screen*)malloc(sizeof(Screen));
	screen->controller = createController(si);
	return screen;
}

void s_initialize(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	printf("Initialize Screen\n");
	c_initialize(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects);
}
int s_update(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects,
	Event gameEvent)
{
	printf("Update Screen\n");
	return c_update(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects, gameEvent);
}

void s_destroy(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	printf("Destroy Screen\n");
	c_destroy(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects);
	free(screen);
}