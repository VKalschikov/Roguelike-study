#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>

#include "drawer.h"
#include "../vectors.h"
#include "../GameObjects/gameobjectsinfo.h"



void loadTextures(Drawer *drawer)
{
	printf("Load Textures\n");

	drawer->textures = (sfTexture**)malloc(sizeof(sfTexture*)*6);
	drawer->types = (GameObjectName*)malloc(sizeof(GameObjectName)*6);

	drawer->textures[0] = sfTexture_createFromFile("assets/floor.png",NULL);
	drawer->types[0] = Floor;
	drawer->textures[1] = sfTexture_createFromFile("assets/wall.png",NULL);
	drawer->types[1] = Wall;
	drawer->textures[2] = sfTexture_createFromFile("assets/apple.png",NULL);
	drawer->types[2] = Apple;
	drawer->textures[3] = sfTexture_createFromFile("assets/sword.png",NULL);
	drawer->types[3] = Sword;
	drawer->textures[4] = sfTexture_createFromFile("assets/bottleofpoison.png",NULL);
	drawer->types[4] = BottleOfPoison;
	drawer->textures[5] = sfTexture_createFromFile("assets/player.png",NULL);
	drawer->types[5] = Player;

	drawer->numberOfTextures = 6;
}

Drawer *createDrawer(GameObjectsInfo *goinfo)
{
	printf("Create Drawer\n");
	Drawer *drawer = (Drawer*)malloc(sizeof(Drawer));
	drawer -> goinfo = goinfo;
	loadTextures(drawer);
	return drawer;
}

void drawer_draw(Drawer *drawer, sfRenderWindow* window, int currentScreen)
{
	printf("Draw\n");
	GameObject *go;
	sfSprite *sprite = sfSprite_create();

	sfVector2f pos;
	sfVector2f scale = {2,2};
	sfSprite_setScale(sprite, scale);
	for(int i=0; i<drawer->goinfo->staticGameObjects[currentScreen]->currentAmount;i++)
	{
		go = gov_get(drawer->goinfo->staticGameObjects[currentScreen], i);
		for(int j=0;j<drawer->numberOfTextures;j++)
		{
			if(go->typeOfObject == drawer->types[j])
			{
				sfSprite_setTexture(sprite, drawer->textures[j], sfTrue);
				pos.x = go->xPos*20;
				pos.y = go->yPos*20;
				sfSprite_setPosition(sprite, pos);
			}
			sfRenderWindow_drawSprite(window, sprite, NULL);
		}
	}
	for(int i=0; i<drawer->goinfo->dynamicGameObjects[currentScreen]->currentAmount;i++)
	{
		go = gov_get(drawer->goinfo->dynamicGameObjects[currentScreen], i);
		for(int j=0;j<drawer->numberOfTextures;j++)
		{
			if(go->typeOfObject == drawer->types[j])
			{
				sfSprite_setTexture(sprite, drawer->textures[j], sfTrue);
				pos.x = go->xPos*20;
				pos.y = go->yPos*20;
				sfSprite_setPosition(sprite, pos);
			}
			sfRenderWindow_drawSprite(window, sprite, NULL);
		}
	}
}

void drawer_destroy(Drawer *drawer)
{
	printf("Destroy Drawer\n");
	for(int i=0;i<drawer->numberOfTextures;i++)
		free(drawer->textures[i]);
	free(drawer->textures);
	free(drawer->types);
	free (drawer);
}