#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vectors/valuesvector.h"
#include "../enums.h"

typedef struct {
	GameObjectName typeOfObject;
	ValuesVector *valuesVector;
	int xPos;
	int yPos;
} GameObject;

//TODO заменить values и nameOfValues на структуру

GameObject *createGameObject(GameObjectName type,  ValuesVector *values, int xPos, int yPos);
GameObject *createGameObjectC(GameObject* go);
void go_setValue(GameObject *go, ValueName name, int value);
int go_getValue(GameObject *go, ValueName name);
void go_destroy(GameObject *GameObject);

GameObject *createWall(int xPos, int yPos);
GameObject *createFloor(int xPos, int yPos);

GameObject *createPlayer(int xPos, int yPos, CharacterClass charClass);
GameObject *createApple(int xPos, int yPos, int healing);
GameObject *createSword(int xPos, int yPos, int addingDamage);
GameObject *createBottleOfPoison(int xPos, int yPos, int damage);
GameObject *createRat(int xPos, int yPos, int health, int damage);
#endif