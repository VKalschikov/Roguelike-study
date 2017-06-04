#ifndef SCREENINFO_H
#define SCREENINFO_H

#include "../vectors.h"

typedef struct{
	int (*update)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues,
		Event gameEvent);

	void (*initialize)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,
		void *uniqueValues);

	void (*destroy)(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,	
		void *uniqueValues
		);

	void *uniqueValues;
} ScreenInfo;

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
);

int si_update(
	ScreenInfo *si, 
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,
	Event gameEvent);

void si_initialize(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio);

void si_destroy(
	ScreenInfo *si,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio);

#endif