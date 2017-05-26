#ifndef CLASSENUM_H
#define CLASSENUM_H

typedef enum{
	Warrior = 0,
	Mage = 1
} CharacterClass;

static const char *CharacterClassStrings[] = {
	"Warrior",
	"Mage"
};

const char *getCharacterClass(CharacterClass enumVal )
{
  return CharacterClassStrings[enumVal];
}

#endif