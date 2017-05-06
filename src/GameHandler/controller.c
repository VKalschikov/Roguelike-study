#include <stdlib.h>
#include "controller.h"

Controller *createController(void (*func)(GameObject *gameObjects, GUIObject *guiObjects))
{
	Controller *cont = (Controller*)malloc(sizeof(Controller));
	cont->update = func;
	return cont;
}

void c_update(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects)
{
	controller->update(gameObjects, guiObjects);
}

void c_destroy(Controller *controller)
{
	free (controller);
}