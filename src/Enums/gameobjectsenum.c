#include "gameobjectsenum.h"

const char * getGameObjectName( GameObjectName enumVal )
{
	const char *GameObjectNameStrings[] = {
	"Player",
	"Wall",
	"Floor",
	"Apple",
	"Sword",
	"BottleOfPoison"
	};
  return GameObjectNameStrings[enumVal];
}