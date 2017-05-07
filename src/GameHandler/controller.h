#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../GameObjects/gameobject.h"
#include "../GameObjects/guiobject.h"

typedef struct{
	ScreenInfo *screeninfo;
} Controller;

Controller *createController(ScreenInfo *si);

void c_initialize(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects);

int c_update(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects);

void c_destroy(Controller *controller);

#endif  