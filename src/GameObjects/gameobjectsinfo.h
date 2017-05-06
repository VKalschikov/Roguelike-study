#ifndef GAMEOBJECTSINFO_H
#define GAMEOBJECTSINFO_H

#include "gameobject.h"
#include "guiobject.h"

typedef struct{
	GameObjects **gameObjects;
	GUIObjects **GUIObjects;
} GameObjectsInfo;

GameObjectsInfo *createGameObjectsInfo();
void goi_destroy(GameObjectsInfo *goi);

#endif