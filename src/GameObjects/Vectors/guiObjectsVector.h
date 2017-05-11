#ifndef GUIOBJECTSVECTOR_H
#define GUIONJECTSVECTOR_H

#include "../guiobject.h"

typedef struct{
	GUIObject *guiObjects;
} GUIObjectsVector;

GUIObjectsVector *creatGUIObjectsVector();

void guiov_add(GUIObjectsVector *guiov, GUIObject *go);
void guiov_removeI(GUIObjectsVector *guiov, int index);
void guiov_removeV(GUIObjectsVector *guiov, GUIObject *guio);
int guiov_find(GUIObjectsVector *guiov, GUIObject *guio);
GUIObject guiov_get(GUIObjectsVector *guiov, int index);

#endif