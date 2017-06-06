#ifndef CLASSENUM_H
#define CLASSENUM_H

typedef enum{
	Warrior = 0,
	Mage = 1
} CharacterClass;

const char *getCharacterClass(CharacterClass enumVal );

#endif