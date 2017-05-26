#include <stdlib.h>
#include "gamescreen.h"
#include "../screeninfo.h"
#include "../screen.h"
#include "../controller.h"
#include "../../vectors.h"
#include "../../enums.h"
#include "../../GameObjects/gameobject.h"

#define STANDART_MAP_SIZE 50

void updateGameObject(GameObject *go)
{ //
}


void generateMap(
	GameObject ****map,
	int sizeX,
	int sizeY,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo
)
{
	*map = (GameObject***)malloc(sizeof(GameObject**)*STANDART_MAP_SIZE);
	for(int i=0; i<STANDART_MAP_SIZE; i++)
	{
		(*map)[i] = (GameObject**)malloc(sizeof(GameObject*)*STANDART_MAP_SIZE);
		for(int j=0; j<STANDART_MAP_SIZE; j++)
		{
			if(i==0 || i== STANDART_MAP_SIZE-1 || j==0 ||j==STANDART_MAP_SIZE-1)
			{
				gov_add(staticgo, createWall(j,i));
				(*map)[j][i] = gov_get(staticgo, staticgo->currentAmount-1);
			}
			else
			{
				gov_add(staticgo, createFloor(j,i));
				(*map)[j][i] = gov_get(staticgo, staticgo->currentAmount-1);
			}
		}
	}
	(*map)[25][1] = createPlayer(1, 25, Warrior);
}


Screen *createGameScreen(int numberOfScreen)
{
	GameObject ***map;
	map = 0;
	ScreenInfo *si = createScreenInfo(gs_initializeFunc, gs_updateFunc, gs_destroy, map);
	return createScreen(si, numberOfScreen);
}

int gs_updateFunc(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
)
{
	for(int i=0;i<dynamicgo->currentAmount;i++)
		updateGameObject(gov_get(dynamicgo, i));
	return 0;
}

void gs_initializeFunc(
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,		
	void *uniqueValues
)
{
	generateMap(
		(GameObject****)(&uniqueValues),
		STANDART_MAP_SIZE,
		STANDART_MAP_SIZE,
		staticgo,
		dynamicgo
	);
	
}
void gs_destroy(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
)
{
	gov_destroy(staticgo);
	gov_destroy(dynamicgo);
	guiov_destroy(guio);
	for(int i=0;i<STANDART_MAP_SIZE;i++)
		free(((GameObject***)uniqueValues)[i]);
	free(uniqueValues);
}