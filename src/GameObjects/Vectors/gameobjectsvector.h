#ifndef GAMEOBJECTSVECTOR_H
#define GAMEOBJECTSVECTOR_H

#include "../gameobject.h"
#include "../../enums.h"

typedef struct{
	int maxAmount;
	int currentAmount;
	GameObject **gameObjects;
} GameObjectsVector;

GameObjectsVector *createGameObjectsVector();

void gov_add(GameObjectsVector *gov, GameObject *go);
void gov_removeI(GameObjectsVector *gov, int index);
void gov_removeV(GameObjectsVector *gov, GameObject *go);
int gov_find(GameObjectsVector *gov, GameObject *g);
int gov_findByType(GameObjectsVector *gov, GameObjectName type);
void gov_increaseMemory(GameObjectsVector *gov);
void gov_decreaseMemory(GameObjectsVector *gov);
GameObject *gov_get(GameObjectsVector *gov, int index);
void gov_destroy(GameObjectsVector *gov);

#endif