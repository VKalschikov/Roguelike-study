#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "value.h"

typedef struct {
	char *typeOfObject;
	int numberOfValues;
	Value **values;
	int xPos;
	int yPos;
} GameObject;

//TODO заменить values и nameOfValues на структуру

GameObject *createGameObject(char *type, int number, Value **values, int xPos, int yPos);
void go_setValue(GameObject *go, const char *name, int value);
int go_getValue(GameObject *go, const char *name, int value);
void go_destroy(GameObject *GameObject);

#endif