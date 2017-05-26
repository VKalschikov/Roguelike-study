#include <stdlib.h>

#include "gameobjectsvector.h"
#include "../gameobject.h"

#define STD_AMOUNT_OF_GOBJECTS 40


GameObjectsVector *createGameObjectsVector()
{
	GameObjectsVector *gov = (GameObjectsVector*)malloc(sizeof(GameObjectsVector));
	gov->maxAmount = STD_AMOUNT_OF_GOBJECTS ;
	gov->currentAmount = 0;
	gov->gameObjects = (GameObject**)malloc(sizeof(GameObject*)*gov->maxAmount);
	return gov;
}

void gov_add(GameObjectsVector *gov, GameObject *go)
{
	if(gov->currentAmount == gov->maxAmount)
		gov_increaseMemory(gov);
	gov->gameObjects[gov->currentAmount] = go;
	gov->currentAmount++;
}

void gov_removeI(GameObjectsVector *gov, int index)
{
	if(index<gov->currentAmount)
	{
		for(int i=index; i<gov->currentAmount-1; i++)
		{
			gov->gameObjects[i] = gov->gameObjects[i+1];
		}
		gov->gameObjects[gov->currentAmount-1]=NULL;
		gov->currentAmount--;
		if((gov->maxAmount-gov->currentAmount)>STD_AMOUNT_OF_GOBJECTS +5)
			gov_decreaseMemory(gov);
	}
}

void gov_removeV(GameObjectsVector *gov, GameObject *go)
{
	int index = gov_find(gov, go);
	if(index!=-1)
	{
		gov_removeI(gov, index);
	}
}

int gov_find(GameObjectsVector *gov, GameObject *go)
{
	int index = -1;
	for(int i=0;i<gov->currentAmount;i++)
	{
		if(go==gov->gameObjects[i])
		{
			index = i;
		}
	}
	return index;
}

void gov_increaseMemory(GameObjectsVector *gov)
{
	GameObject **newA = (GameObject**)malloc(sizeof(GameObject*)*gov->maxAmount+STD_AMOUNT_OF_GOBJECTS );
	for(int i=0;i<gov->currentAmount;i++)
	{
		newA[i] = gov->gameObjects[i];
	}
	free(gov->gameObjects);
	gov->gameObjects = newA;
	gov->maxAmount+=STD_AMOUNT_OF_GOBJECTS ;
}

void gov_decreaseMemory(GameObjectsVector *gov)
{
	GameObject **newA = (GameObject**)malloc(sizeof(GameObject*)*gov->maxAmount-STD_AMOUNT_OF_GOBJECTS );
	for(int i=0;i<gov->currentAmount;i++)
	{
		newA[i] = gov->gameObjects[i];
	}
	free(gov->gameObjects);
	gov->gameObjects = newA;
	gov->maxAmount-= STD_AMOUNT_OF_GOBJECTS ;
}

GameObject *gov_get(GameObjectsVector *gov, int index)
{
	if(index<gov->currentAmount)
		return gov->gameObjects[index];
	return 0;
}

void gov_destroy(GameObjectsVector *gov)
{
	for(int i=0;i<gov->currentAmount;i++)
		free(gov->gameObjects[i]);
	free(gov);
}