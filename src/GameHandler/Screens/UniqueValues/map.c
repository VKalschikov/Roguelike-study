#include "map.h"
#include <stdlib.h>

Map *createMap()
{
	Map *map = (Map*)malloc(sizeof(Map));
	return map;
}

void map_initialize(Map *map,int sizeX, int sizeY)
{
	map->sizeX = sizeX;
	map->sizeY = sizeY;
	map->field = (GameObject***)malloc(sizeof(GameObject**)*sizeY);
	
	for(int i=0; i<sizeY; i++)
		map->field[i] = (GameObject**)malloc(sizeof(GameObject*)*sizeX);

}

GameObject *map_get(Map *map, int x, int y)
{
	if(x < map->sizeX && y < map->sizeY && x>-1 && y>-1)
		return map->field[y][x];
	return map->field[0][0];
}

void map_set(Map *map, int x, int y, GameObject *go)
{
	if(x < map->sizeX && y < map->sizeY && x>-1 && y>-1)
		map->field[y][x] = go;
}

void map_destroy(Map *map)
{
	for(int i=0; i<map->sizeY; i++)
		free(map->field[i]);
	free (map->field);
	free (map);
}