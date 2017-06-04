#ifndef MAP_H
#define MAP_H

#include "../../../GameObjects/gameobject.h"

typedef struct{
	int sizeX;
	int sizeY;
	GameObject ***field;
} Map;

Map *createMap();

void map_initialize(Map *map, int sizeX, int sizeY);
GameObject *map_get(Map *map, int x, int y);
void map_set(Map *map, int x, int y, GameObject *go);
void map_destroy(Map *map);

#endif