#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

typedef struct {
	char *typeOfObject;
	int numberOfValues;
	int *values;
	char **nameOfValues;
	int xPos;
	int yPos;
} GameObject;

//TODO заменить values и nameOfValues на структуру

GameObject *createGameObject(char *type, int number, int *values, char **nameOfValues, int xPos, int yPos);
void go_destroy(GameObject *GameObject);

#endif