#include "valuesenum.h"

const char * getValueName( int enumVal )
{
	const char *ValueNameStrings[] = {
	"Health",
	"Defense",
	"Attack",
	"IsFriendly",
	"IsPlayer",
	"IsDynamic",
	"Class",
	"IsFloor",
	"IsWall"
};
  return ValueNameStrings[enumVal];
}