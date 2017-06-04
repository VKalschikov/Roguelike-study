#ifndef GAMEOBJECTSENUM_H
#define GAMEOBJECTSENUM_H

typedef enum{
	Player = 0,
	Wall = 1,
	Floor = 2,
	Apple = 3,
	Sword = 4,
	BottleOfPoison = 5
} GameObjectName;

//const char * getGameObjectName( GameObjectName enumVal );

#endif