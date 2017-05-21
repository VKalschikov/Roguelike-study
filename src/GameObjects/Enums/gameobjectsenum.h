#ifndef GAMEOBJECTSENUM_H
#define GAMEOBJECTSENUM_H

typedef enum{
	Wall = 1,
	Floor = 2,
	Apple = 3,
	Sword = 4,
	BottleOfPison = 5
} GameObjectName;

static const char *GameObjectNameStrings[] = {
	"Wall",
	"Floor",
	"Apple",
	"Sword",
	"BottleOfPison"
};

const char * getGameObjectName( int enumVal )
{
  return GameObjectNameStrings[enumVal];
}
#endif