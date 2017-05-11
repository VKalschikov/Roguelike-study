#ifndef GAMEOBJECTSVECTOR_H
#define GAMEONJECTSVECTOR_H

#include "../gameobject.h"

typedef struct{
	GameObject *gameObjects;
} GameObjectsVector;

GameObjectsVector *creatGameObjectsVector();

void gov_add(GameObjectsVector *gov, GameObject *go);
void gov_removeI(GameObjectsVector *gov, int index);
void gov_removeV(GameObjectsVector *gov, GameObject *go);
int gov_find(GameObjectsVector *gov, GameObject *go);
GameObject gov_get(GameObjectsVector *gov, int index);

#endif