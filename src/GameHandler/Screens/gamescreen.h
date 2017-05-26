#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "../screen.h"
#include "../../vectors.h"


Screen *createGameScreen(int numberOfScreen);
int gs_updateFunc(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		);
void gs_initializeFunc(
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,		
	void *uniqueValues
	);
void gs_destroy(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		);
#endif