#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vectors/valuesvector.h"

typedef struct {
	char *typeOfObject;
	int numberOfValues;
	ValuesVector *valuesVector;
	int xPos;
	int yPos;
} GameObject;

//TODO заменить values и nameOfValues на структуру

GameObject *createGameObject(char *type, int number, ValuesVector *values, int xPos, int yPos);
void go_setValue(GameObject *go, const char *name, int value);
int go_getValue(GameObject *go, const char *name);
void go_destroy(GameObject *GameObject);

#endif