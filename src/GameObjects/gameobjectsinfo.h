#ifndef GAMEOBJECTSINFO_H
#define GAMEOBJECTSINFO_H

#include "Vectors/gameobjectsvector.h"
#include "Vectors/guiobjectsvector.h"

typedef struct{
	int numberOfScreens;
	GameObjectsVector **staticGameObjects;
	GameObjectsVector **dynamicGameObjects;
	GUIObjectsVector **GUIObjects;
} GameObjectsInfo;

GameObjectsInfo *createGameObjectsInfo(int numberOfScreens);
void goi_destroy(GameObjectsInfo *goi);

#endif