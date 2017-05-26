#ifndef GUIOBJECTSENUM_H
#define GUIOBJECTSENUM_H

typedef enum{
	Button = 0,
	String = 1
} GUIObjectName;

static const char *GUIObjectNameStrings[] = {
	"Button",
	"String"
};

const char * getGUIObjectName( int enumVal )
{
  return GUIObjectNameStrings[enumVal];
}
#endif