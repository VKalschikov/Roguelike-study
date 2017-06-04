#include "classenum.h"


const char *getCharacterClass(CharacterClass enumVal )
{
	const char *CharacterClassStrings[] = {
	"Warrior",
	"Mage"
	};
  return CharacterClassStrings[enumVal];
}