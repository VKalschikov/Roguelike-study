#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "../screen.h"
#include "../../vectors.h"

Screen *createGameOverScreen(int numberOfScreen);
int gos_updateFunc(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues,
		Event gameEvent
		);
void gos_initializeFunc(
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,		
	void *uniqueValues
	);
void gos_destroy(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		);

#endif