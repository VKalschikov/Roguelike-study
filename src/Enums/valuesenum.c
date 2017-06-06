#include "valuesenum.h"

const char * getValueName( int enumVal )
{
	const char *ValueNameStrings[] = {
	"MaxHealth",
	"Defense",
	"Attack",
	"IsFriendly",
	"IsPlayer",
	"Class"
	"IsFloor",
	"IsWall",
	"CurrentHealth",
	"IsEnemy"
};
  return ValueNameStrings[enumVal];
}