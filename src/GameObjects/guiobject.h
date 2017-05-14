#ifndef GUIOBJECT_H
#define GUIOBJECT_H

typedef struct{
	char *typeOfObject;
	int numberOfObjectOnScreen;
	int posX;
	int posY;
} GUIObject;

GUIObject *createGUIObject(char *type, int numberOfObjectOnScreen, int posX, int posY);
void guio_destroy(GUIObject *guio);

#endif