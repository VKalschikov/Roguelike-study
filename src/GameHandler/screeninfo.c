#include "screeninfo.h"
#include <stdlib.h>

#include "../GameObjects/Vectors/gameobjectsvector.h"
#include "../GameObjects/Vectors/guiobjectsvector.h" 	

ScreenInfo *createScreenInfo(
	void (*initialize)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues),
	int (*func)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues),
	void (*destroy)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		),
	void *uniqueValues
)
{
	ScreenInfo *si = (ScreenInfo*)malloc(sizeof(ScreenInfo));
	si->update = func;
	si->initialize = initialize;
	si->destroy = destroy;
	si->uniqueValues = uniqueValues;
	return si;
}

int si_update(
	ScreenInfo *si, 
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio)
{
	return si->update(staticgo, dynamicgo, guio,  si->uniqueValues);
}
void si_initialize(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio)
{
	si->initialize(staticgo, dynamicgo, guio,  si->uniqueValues);
}

void si_destroy(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio)
{
	si->destroy(staticgo, dynamicgo, guio, si->uniqueValues);
	free (si);
}