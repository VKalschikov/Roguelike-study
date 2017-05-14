#include <stdlib.h>
#include "guiobject.h"

GUIObject *createGUIObject(char *type, int number, int posX, int posY)
{
	GUIObject *guio = (GUIObject*)malloc(sizeof(GUIObject));
	guio->typeOfObject = type;
	guio->numberOfObjectOnScreen = number;
	guio->posX = posX;
	guio->posY = posY;
	return guio;
}
void guio_destroy(GUIObject *guio)
{
	free(guio);
}