#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vectors/valuesvector.h"
#include "../enums.h"

typedef struct {
	GameObjectName typeOfObject;
	int numberOfValues;
	ValuesVector *valuesVector;
	int xPos;
	int yPos;
} GameObject;

//TODO заменить values и nameOfValues на структуру

GameObject *createGameObject(GameObjectName type, int number, ValuesVector *values, int xPos, int yPos);
void go_setValue(GameObject *go, ValueName name, int value);
int go_getValue(GameObject *go, ValueName name);
void go_destroy(GameObject *GameObject);

GameObject *createWall(int xPos, int yPos);
GameObject *createFloor(int xPos, int yPos);

GameObject *createPlayer(int xPos, int yPos, CharacterClass charClass);
#endif