#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void updateGUIObject(GUIObject *guio, GameObject *player)
{
	if(guio->typeOfObject == HealthString|| guio->typeOfObject == AttackString)
	{
		char buffer1[50], buffer2[50];
		if(guio->typeOfObject==HealthString)
		{
			strcpy(buffer1, "Health: ");
			sprintf(buffer2, "%d", go_getValue(player, CurrentHealth));
		}else if(guio->typeOfObject == AttackString)
		{
			strcpy(buffer1, "Attack: ");
			sprintf(buffer2, "%d", go_getValue(player, Attack));
		}
		strcat(buffer1, buffer2);
		printf("Error1\n");
		strcpy(guio->object,buffer1);
		printf("Error2\n");
	}
}


void generateMap(
	Map *map,
	int sizeX,
	int sizeY,
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio
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
		map_set(map, player->xPos, player->yPos, player);
	}
	else
	{
		player = gov_get(dynamicgo, gov_findByType(dynamicgo, Player));
		map_set(map, player->xPos, player->yPos, player);
	}
	GameObject *apple = createApple(5, 5 , 10);
	gov_add(dynamicgo, apple);
	map_set(map, apple->xPos, apple->yPos, apple);

	GameObject *sword = createSword(5, 10, 5);
	gov_add(dynamicgo, sword);
	map_set(map, sword->xPos, sword->yPos, sword);

	GameObject *bottleOfPoison = createBottleOfPoison(5, 15 , 50);
	gov_add(dynamicgo, bottleOfPoison);
	map_set(map, bottleOfPoison->xPos, bottleOfPoison->yPos, bottleOfPoison);

	for(int i=0;i<guio->currentAmount;i++)
		updateGUIObject(guiov_get(guio,i),player);
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
		GUIObjectsVector *guiov,		
		void *uniqueValues,
		Event gameEvent
)
{
	GameObject *player = gov_get(dynamicgo, gov_findByType(dynamicgo, Player));
	int newX = 0;
	int newY = 0;
	Map *map = (Map*)uniqueValues;
	printf("Player yPos %d\n", player->yPos);
	switch(gameEvent)
	{
		case pressKeyUp:
			if( player->yPos-1>=0 && player->yPos-1<map->sizeY)
			{
				if(map_get(map, player->xPos, player->yPos-1)->typeOfObject!=Wall)
				{
					newX = player->xPos;
					newY = player->yPos-1;
				}
				else
				{
					return 0;
				}
			}
		break;

		case pressKeyRight:
			if( player->xPos+1>=0 && player->xPos+1<map->sizeX)
			{
				if(map_get(map, player->xPos+1, player->yPos)->typeOfObject!=Wall)
				{
						newX = player->xPos+1;
						newY = player->yPos;
				}
				else
				{
					return 0;
				}
			}
		break;

		case pressKeyDown:
			if( player->yPos+1>=0 && player->yPos+1<map->sizeY)
			{
				if(map_get(map, player->xPos, player->yPos+1)->typeOfObject!=Wall)
				{
						newX = player->xPos;
						newY = player->yPos+1;
				}
				else
				{
					return 0;
				}
			}
		break;
		
		case pressKeyLeft:
			if( player->xPos-1>=0 && player->xPos-1<map->sizeX)
			{
				if(map_get(map, player->xPos-1, player->yPos)->typeOfObject!=Wall)
				{
						newX = player->xPos-1;
						newY = player->yPos;
				}
				else
				{
					return 0;
				}
			}
		break;

		case null:
		default:
			newY = 0;
			newX = 0;
		break;
	}
	if(map_get(map, newX, newY)->typeOfObject == Floor)
	{
		GameObject *go = map_get(map, newX, newY);
		go->xPos = player->xPos;
		go->yPos = player->yPos;
		player->xPos = newX;
		player->yPos = newY;
		map_set(map, player->xPos, player->yPos, player);
		map_set(map, go->xPos, go->yPos, go);

	}
	else if(map_get(map, newX, newY)->typeOfObject == Apple)
	{
		int heal = go_getValue(map_get(map, newX, newY), Healing);
		go_destroy(map_get(map, newX, newY));
		GameObject *go = createFloor(player->xPos, player->yPos);
		player->xPos = newX;
		player->yPos = newY;
		map_set(map, player->xPos, player->yPos, player);
		map_set(map, go->xPos, go->yPos, go);
		go_setValue(player, CurrentHealth, go_getValue(player, CurrentHealth)+heal);
		if(go_getValue(player, CurrentHealth)>go_getValue(player, MaxHealth))
			go_setValue(player, CurrentHealth, go_getValue(player, MaxHealth));
	}else if(map_get(map, newX, newY)->typeOfObject == Sword)
	{
		int addingDamage = go_getValue(map_get(map, newX, newY), AddingDamage);
		go_destroy(map_get(map, newX, newY));
		GameObject *go = createFloor(player->xPos, player->yPos);
		player->xPos = newX;
		player->yPos = newY;
		map_set(map, player->xPos, player->yPos, player);
		map_set(map, go->xPos, go->yPos, go);
		go_setValue(player, Attack, go_getValue(player, Attack)+addingDamage);
	}else if(map_get(map, newX, newY)->typeOfObject == BottleOfPoison)
	{
		int damage = go_getValue(map_get(map, newX, newY), Damage);
		go_destroy(map_get(map, newX, newY));
		GameObject *go = createFloor(player->xPos, player->yPos);
		player->xPos = newX;
		player->yPos = newY;
		map_set(map, player->xPos, player->yPos, player);
		map_set(map, go->xPos, go->yPos, go);
		go_setValue(player, CurrentHealth, go_getValue(player, CurrentHealth)-damage);	
	}
	for(int i=0;i<dynamicgo->currentAmount;i++)
		updateGameObject(gov_get(dynamicgo, i));

	for(int i=0; i<guiov->currentAmount;i++)
		updateGUIObject(guiov_get(guiov, i), player);
	return 0;
}

void gs_initializeFunc(
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,		
	void *uniqueValues
)
{
	guiov_add(guio, createGUIObject(HealthString, 501, 10, (char*)malloc(sizeof(char)*50)));
	guiov_add(guio, createGUIObject(AttackString, 501, 50, (char*)malloc(sizeof(char)*50)));
	generateMap(
		(Map*)uniqueValues,
		STANDART_MAP_SIZE,
		STANDART_MAP_SIZE,
		staticgo,
		dynamicgo,
		guio
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