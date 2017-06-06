#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include "../enums.h"

typedef struct{
	GUIObjectName typeOfObject;
	int posX;
	int posY;
	void *object;
} GUIObject;

GUIObject *createGUIObject(GUIObjectName type, int posX, int posY, void *object);
void guio_destroy(GUIObject *guio);

#endif