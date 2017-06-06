#include "guiobjectsenum.h"

const char * getGUIObjectName( int enumVal )
{
	const char *GUIObjectNameStrings[] = {
	"Button",
	"HealthString"
	};
  return GUIObjectNameStrings[enumVal];
}