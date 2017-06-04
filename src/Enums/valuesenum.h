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
	Class = 7,
	IsFloor = 8,
	IsWall = 9
}ValueName;

//const char * getValueName( int enumVal );
#endif