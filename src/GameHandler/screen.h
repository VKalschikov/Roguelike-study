#ifndef SCREEN_H
#define SCREEN_H

#include "controller.h"
#include "screeninfo.h"

#include "../GameObjects/gameobject.h"
#include "../GameObjects/guiobject.h"

typedef struct{
	Controller *controller;
} Screen;

Screen *createScreen();
void s_initialize(Screen *screen, GameObject *gameObjects, GUIObject *guiObjects);
int s_update(Screen *screen, GameObject *gameObjects, GUIObject *guiObjects);
void s_destroy(Screen *screen);

#endif 