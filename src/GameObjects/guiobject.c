#include <stdlib.h>
#include "guiobject.h"
#include "../enums.h"

GUIObject *createGUIObject(GUIObjectName type, int posX, int posY, void *object)
{
	GUIObject *guio = (GUIObject*)malloc(sizeof(GUIObject));
	guio->typeOfObject = type;
	guio->object = object;
	guio->posX = posX;
	guio->posY = posY;
	return guio;
}
void guio_destroy(GUIObject *guio)
{
	free (guio->object);
	free(guio);
}