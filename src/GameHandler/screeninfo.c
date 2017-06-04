#include "screeninfo.h"
#include <stdlib.h>
#include <stdio.h>

#include "../vectors.h"	

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
		void *uniqueValues,
		Event gameEvent),
	void (*destroy)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		),
	void *uniqueValues
)
{
	printf("Create Screen Info\n");
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
	GUIObjectsVector *guio,
	Event gameEvent)
{
	printf("Screen Info Update\n");
	return si->update(staticgo, dynamicgo, guio,  si->uniqueValues, gameEvent);
}
void si_initialize(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio)
{
	printf("Screen Info Initialize\n");
	si->initialize(staticgo, dynamicgo, guio,  si->uniqueValues);
}

void si_destroy(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio)
{
	printf("Screen Info Destroy\n");
	si->destroy(staticgo, dynamicgo, guio, si->uniqueValues);
	free (si);
}