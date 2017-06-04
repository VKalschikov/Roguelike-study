#include "guiobjectsenum.h"

const char * getGUIObjectName( int enumVal )
{
	const char *GUIObjectNameStrings[] = {
	"Button",
	"String"
	};
  return GUIObjectNameStrings[enumVal];
}