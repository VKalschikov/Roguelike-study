#ifndef GAMEOBJECTSENUM_H
#define GAMEOBJECTSENUM_H

typedef enum{
	Player = 0,
	Wall = 1,
	Floor = 2,
	Apple = 3,
	Sword = 4,
	BottleOfPison = 5
} GameObjectName;

static const char *GameObjectNameStrings[] = {
	"Player",
	"Wall",
	"Floor",
	"Apple",
	"Sword",
	"BottleOfPison"
};

const char * getGameObjectName( GameObjectName enumVal )
{
  return GameObjectNameStrings[enumVal];
}
#endif