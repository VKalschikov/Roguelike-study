#include "gameobject.h"
#include <stdlib.h>

GameObject *createGameObject(char *typeOfObject, int numberOfValues, int *values, char **nameOfValues, int xPos, int yPos)
{
	GameObject *go = (GameObject*)malloc(sizeof(GameObject));
	go->typeOfObject = typeOfObject;
	go->numberOfValues = numberOfValues;
	go->values = values;
	go->nameOfValues = nameOfValues;
	go->xPos = xPos;
	go->yPos = yPos;
	return go;
}

void go_destroy(GameObject *go)
{
	free(go->typeOfObject);
	free(go->values);
	for(int i=0;i< go->nameOfValues; i++)
		free(go->nameOfValues[i]);
	free(go->nameOfValues);
	free(go);
}	