#include <stdlib.h>
#include "controller.h"
#include "screenInfo"

Controller *createController(ScreenInfo *si)
{
	Controller *cont = (Controller*)malloc(sizeof(Controller));
	cont->screenInfo = si;
	return cont;
}

void c_initialize(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects)
{
	si_initialize(controller->si, gameObjects, guiObjects);
}

int c_update(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects)
{
	return si_update(si, gameObjects, guiObjects);
}

void c_destroy(Controller *controller)
{
	si_destroy(controller->screenInfo);
	free (controller);
}