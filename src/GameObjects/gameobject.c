#include "gameobject.h"
#include "Vectors/valuesvector.h"
#include <stdlib.h>
#include <string.h>

GameObject *createGameObject(char *type, int number, ValuesVector *values, int xPos, int yPos)
{
	GameObject *go = (GameObject*)malloc(sizeof(GameObject));
	go->typeOfObject = type;
	go->numberOfValues = number;
	go->valuesVector = values;
	go->xPos = xPos;
	go->yPos = yPos;
	return go;
}

void go_setValue(GameObject *go, ValueName name, int value)
{
	Value *temp =  vv_getByName(go->valuesVector, name);
	if(temp!=NULL)
		temp->value = value;
}
int go_getValue(GameObject *go, ValueName name)
{
	Value *temp =  vv_getByName(go->valuesVector, name);
	if(temp!=NULL)
		return temp->value;
	return 0;
}

void go_destroy(GameObject *go)
{
	free(go->typeOfObject);
	vv_destroy(go->valuesVector);
	free(go);
}	