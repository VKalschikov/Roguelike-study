#include <stdlib.h>
#include <stdio.h>
#include "UniqueValues/map.h"
#include "gamescreen.h"
#include "../screeninfo.h"
#include "../screen.h"
#include "../controller.h"
#include "../../vectors.h"
#include "../../enums.h"
#include "../../GameObjects/gameobject.h"

#define STANDART_MAP_SIZE 25

void updateGameObject(GameObject *go)
{ 
}


void generateMap(
	Map *map,
	int sizeX,
	int sizeY,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo
)
{
	map_initialize(map, sizeX, sizeY);
	for(int i=0; i<sizeY; i++)
	{
		for(int j=0; j<sizeX; j++)
		{
			if(i==0 || i== sizeY-1 || j==0 ||j==sizeX-1)
			{
				gov_add(staticgo, createWall(j,i));
				printf("ADD WALL\n");
				map_set(map, j, i, gov_get(staticgo, staticgo->currentAmount-1));
			}
			else
			{
				gov_add(staticgo, createFloor(j,i));
				printf("ADD FLOOR\n");
				map_set(map, j, i, gov_get(staticgo, staticgo->currentAmount-1));
			}
			printf("j: %d\n",j );
		}
	}
	GameObject *player;
	int index = gov_findByType(dynamicgo, Player);
	if(index==-1)
	{
		player = createPlayer(1, 10, Warrior);
		gov_add(dynamicgo, player);
	}
	else
	{
		player = gov_get(dynamicgo, gov_findByType(dynamicgo, Player));
	}
	map_set(map, 1, 10, player);
}


Screen *createGameScreen(int numberOfScreen)
{
	Map *map = createMap();
	ScreenInfo *si = createScreenInfo(gs_initializeFunc, gs_updateFunc, gs_destroy, map);
	return createScreen(si, numberOfScreen);
}

int gs_updateFunc(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues,
		Event gameEvent
)
{
	GameObject *player = gov_get(dynamicgo, gov_findByType(dynamicgo, Player));
	Map *map = (Map*)uniqueValues;
	printf("Player yPos %d\n", player->yPos);
	switch(gameEvent)
	{
		case pressKeyUp:
			if(player->yPos-1>=0&&player->yPos-1<STANDART_MAP_SIZE)
			{
				if(map_get(map, player->xPos, player->yPos-1)->typeOfObject!=Wall)
				{
					printf("Enter\n");
					player->yPos--;
				}
				else
				{
					return 0;
				}
			}
		break;

		case pressKeyRight:
			if(map_get(map, player->xPos+1, player->yPos)->typeOfObject!=Wall)
			{
				player->xPos++;
			}
			else
			{
				return 0;
			}
		break;

		case pressKeyDown:
			if(map_get(map, player->xPos, player->yPos+1)->typeOfObject!=Wall)
			{
				player->yPos++;
			}
			else
			{
				return 0;
			}
		break;
		
		case pressKeyLeft:
			if(map_get(map, player->xPos-1, player->yPos)->typeOfObject!=Wall)
			{
				player->xPos--;
			}
			else
			{
				return 0;
			}
		break;

		case null:
		default:
		break;
	}
	printf("add Pos to Player\n");
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
		(Map*)uniqueValues,
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
	map_destroy(uniqueValues);
}