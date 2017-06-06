#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.h>

#include "../GameObjects/gameobjectsinfo.h"
#include "../enums.h"

typedef struct {
	GameObjectsInfo *goinfo;
	sfTexture **textures;
	GameObjectName *types;
	int numberOfTextures;
	sfFont* font;
}Drawer;

Drawer *createDrawer(GameObjectsInfo *goinfo);

void drawer_draw(Drawer *drawer, sfRenderWindow* window, int currentScreen);

void drawer_destroy(Drawer *drawer);

#endif 