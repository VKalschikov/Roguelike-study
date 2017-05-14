#include "gameobject.h"
#include "value.h"
#include <stdlib.h>
#include <string.h>

GameObject *createGameObject(char *type, int number, Value **values, int xPos, int yPos)
{
	GameObject *go = (GameObject*)malloc(sizeof(GameObject));
	go->typeOfObject = type;
	go->numberOfValues = number;
	go->values = values;
	go->xPos = xPos;
	go->yPos = yPos;
	return go;
}

void go_setValue(GameObject *go, const char *name, int value)
{
	for(int i=0;i<go->numberOfValues;i++)
	{
		if(!strcmp(go->values[i]->nameOfValue, name))
		{
			go->values[i]->value=value;
		}
	}
}
int go_getValue(GameObject *go, const char *name, int value)
{
	for(int i=0;i<go->numberOfValues;i++)
	{
		if(!strcmp(go->values[i]->nameOfValue, name))
		{
			return go->values[i]->value;
		}
	}
	return -1;
}

void go_destroy(GameObject *go)
{
	free(go->typeOfObject);
	free(go->values);
	for(int i=0;i< go->numberOfValues; i++)
		free(go->values[i]);
	free(go->values);
	free(go);
}	