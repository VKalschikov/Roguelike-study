#include <stdlib.h>
#include "screen.h"

#include "controller.h"
#include "screeninfo.h"
#include "../GameObjects/Vectors/gameobjectsvector.h"
#include "../GameObjects/Vectors/guiobjectsvector.h"

Screen *createScreen(ScreenInfo *si, int numberOfScreen)
{
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
	c_initialize(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects);
}
int s_update(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	return c_update(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects);
}

void s_destroy(
	Screen *screen,
	GameObjectsVector *staticGameObjects,
	GameObjectsVector *dynamicGameObjects,
	GUIObjectsVector *guiObjects)
{
	c_destroy(screen->controller, staticGameObjects, dynamicGameObjects, guiObjects);
	free(screen);
}