#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>

#include "drawer.h"
#include "../vectors.h"
#include "../GameObjects/gameobjectsinfo.h"



void loadTextures(Drawer *drawer)
{
	printf("Load Textures\n");

	drawer->textures = (sfTexture**)malloc(sizeof(sfTexture*)*7);
	drawer->types = (GameObjectName*)malloc(sizeof(GameObjectName)*7);

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
	drawer->textures[6] = sfTexture_createFromFile("assets/rat.png",NULL);
	drawer->types[6] = Rat;

	drawer->numberOfTextures = 7;
}

Drawer *createDrawer(GameObjectsInfo *goinfo)
{
	printf("Create Drawer\n");
	Drawer *drawer = (Drawer*)malloc(sizeof(Drawer));
	drawer -> goinfo = goinfo;
	drawer->font = sfFont_createFromFile("assets/Pixeled.ttf");
	loadTextures(drawer);
	return drawer;
}

void drawer_draw(Drawer *drawer, sfRenderWindow* window, int currentScreen)
{
	printf("Draw\n");
	GameObject *go;
	sfSprite *sprite = sfSprite_create();
	sfText *text = sfText_create();
	sfText_setFont(text, drawer->font);
	sfText_setCharacterSize(text, 20);

	sfVector2f pos;
	sfVector2f scale = {2,2};
	sfSprite_setScale(sprite, scale);
	printf("CurrentScreen : %d\n", currentScreen);
	printf("currentAmount : %d\n", drawer->goinfo->staticGameObjects[currentScreen]->currentAmount);	
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
	printf("Ошибка2\n");
	for(int i=0; i<drawer->goinfo->dynamicGameObjects[currentScreen]->currentAmount;i++)
	{
		go = gov_get(drawer->goinfo->dynamicGameObjects[currentScreen], i);
		for(int j=0;j<drawer->numberOfTextures;j++)
		{
			if(go->typeOfObject == drawer->types[j])
			{
				sfSprite_setTexture(sprite, drawer->textures[0], sfTrue);
				pos.x = go->xPos*20;
				pos.y = go->yPos*20;
				sfSprite_setPosition(sprite, pos);
				sfRenderWindow_drawSprite(window, sprite, NULL);
				sfSprite_setTexture(sprite, drawer->textures[j], sfTrue);
			}
			sfRenderWindow_drawSprite(window, sprite, NULL);
		}
	}
	printf("Ошибка3\n");
	for(int i=0;i<drawer->goinfo->GUIObjects[currentScreen]->currentAmount;i++)
	{
		GUIObject *guio = guiov_get(drawer->goinfo->GUIObjects[currentScreen],i);
		switch(guio->typeOfObject)
		{
			case Button:

			break;

			case HealthString:
			case AttackString:
			case GameOverString:
				sfText_setString(text, guio->object);
				pos.x = guio->posX;
				pos.y = guio->posY;
				sfText_setPosition(text, pos);
			break;
			default:

			break;
		}
		sfRenderWindow_drawText(window, text, NULL);
	}
	sfText_destroy(text);
}

void drawer_destroy(Drawer *drawer)
{
	printf("Destroy Drawer\n");
	for(int i=0;i<drawer->numberOfTextures;i++)
	{
		sfTexture_destroy(drawer->textures[i]);
	}
	sfFont_destroy(drawer->font);
	free(drawer->textures);
	free(drawer->types);
	free (drawer);
}