#ifndef VALUESENUM_H
#define VALUESENUM_H

typedef enum
{
	MaxHealth = 0,
	Defense = 1,
	Attack = 3,
	IsFriendly = 4,
	IsPlayer = 5,
	Class = 6,
	IsFloor = 7,
	IsWall = 8,
	CurrentHealth = 9,
	IsEnemy = 10,
	Healing = 11,
	AddingDamage = 12,
	Damage = 13
}ValueName;

const char * getValueName( int enumVal );
#endif