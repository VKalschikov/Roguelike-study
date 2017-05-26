#ifndef VALUESENUM_H
#define VALUESENUM_H

typedef enum
{
	Health = 0,
	Defense = 1,
	Attack = 3,
	IsFriendly = 4,
	IsPlayer = 5,
	IsDynamic = 6,
	Class = 7
}ValueName;

static const char *ValueNameStrings[] = {
	"Health",
	"Defense",
	"Attack",
	"IsFriendly",
	"IsPlayer",
	"IsDynamic",
	"Class"
};

const char * getValueName( int enumVal )
{
  return ValueNameStrings[enumVal];
}

#endif