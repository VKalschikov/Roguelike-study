#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../GameObjects/gameobject.h"
#include "../GameObjects/guiobject.h"

typedef struct{
	void (*update)(GameObject *gameObjects, GUIObject *guiObjects);
} Controller;

Controller *createController(void (*func)(GameObject *gameObjects, GUIObject *guiObjects));

void c_update(Controller *controller, GameObject *gameObjects, GUIObject *guiObjects);

void c_destroy(Controller *controller);

#endif  