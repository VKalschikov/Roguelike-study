#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "../GameObjects/Vectors/gameobjectsvector.h"
#include "../GameObjects/Vectors/guiobjectsvector.h"

typedef struct{
	int (*update)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues);

	void (*initialize)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues);

	void *uniqueValues;
} ScreenInfo;

ScreenInfo *createScreenInfo(
	int (*func)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues),

	void (*initialize)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues),

	void *uniqueValues);

int si_update(
	ScreenInfo *si, 
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio);

void si_initialize(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio);

void si_destroy(ScreenInfo *si);

#endif