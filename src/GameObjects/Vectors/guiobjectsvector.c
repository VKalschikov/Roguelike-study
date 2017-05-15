#include <stdlib.h>

#include "guiobjectsvector.h"
#include "../guiobject.h"

#define STD_AMOUNT_OF_GUIOBJECTS 40

GUIObjectsVector *createGUIObjectsVector()
{
	GUIObjectsVector *guiov = (GUIObjectsVector*)malloc(sizeof(GUIObjectsVector));
	guiov->maxAmount = STD_AMOUNT_OF_GUIOBJECTS;
	guiov->currentAmount = 0;
	guiov->guiObjects = (GUIObject**)malloc(sizeof(GUIObject*)*guiov->maxAmount);
	return guiov;
}

void guiov_add(GUIObjectsVector *guiov, GUIObject *go)
{
	if(guiov->currentAmount == guiov->maxAmount)
		guiov_increaseMemory(guiov);
	guiov->guiObjects[guiov->currentAmount] = go;
	guiov->currentAmount++;
}

void guiov_removeI(GUIObjectsVector *guiov, int index)
{
	if(index<guiov->currentAmount)
	{
		for(int i=index; i<guiov->currentAmount-1; i++)
		{
			guiov->guiObjects[i] = guiov->guiObjects[i+1];
		}
		guiov->guiObjects[guiov->currentAmount-1]=NULL;
		guiov->currentAmount--;
		if((guiov->maxAmount-guiov->currentAmount)>STD_AMOUNT_OF_GUIOBJECTS +5)
			guiov_decreaseMemory(guiov);
	}
}

void guiov_removeV(GUIObjectsVector *guiov, GUIObject *guio)
{
	int index = guiov_find(guiov, guio);
	if(index!=-1)
	{
		guiov_removeI(guiov, index);
	}
}

int guiov_find(GUIObjectsVector *guiov, GUIObject *guio)
{
	int index = -1;
	for(int i=0;i<guiov->currentAmount;i++)
	{
		if(guio==guiov->guiObjects[i])
		{
			index = i;
		}
	}
	return index;
}

void guiov_increaseMemory(GUIObjectsVector *guiov)
{
	GUIObject **newA = (GUIObject**)malloc(sizeof(GUIObject*)*guiov->maxAmount+STD_AMOUNT_OF_GUIOBJECTS);
	for(int i=0;i<guiov->currentAmount;i++)
	{
		newA[i] = guiov->guiObjects[i];
	}
	free(guiov->guiObjects);
	guiov->guiObjects = newA;
	guiov->maxAmount+=STD_AMOUNT_OF_GUIOBJECTS;
}

void guiov_decreaseMemory(GUIObjectsVector *guiov)
{
	GUIObject **newA = (GUIObject**)malloc(sizeof(GUIObject*)*guiov->maxAmount-STD_AMOUNT_OF_GUIOBJECTS);
	for(int i=0;i<guiov->currentAmount;i++)
	{
		newA[i] = guiov->guiObjects[i];
	}
	free(guiov->guiObjects);
	guiov->guiObjects = newA;
	guiov->maxAmount-= STD_AMOUNT_OF_GUIOBJECTS;
}

GUIObject *guiov_get(GUIObjectsVector *guiov, int index)
{
	return guiov->guiObjects[index];
}

void guiov_destroy(GUIObjectsVector *guiov)
{
	for(int i=0;i<guiov->currentAmount;i++)
		free(guiov->guiObjects[i]);
	free(guiov);
}