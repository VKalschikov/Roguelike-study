#ifndef GUIOBJECTSENUM_H
#define GUIOBJECTSENUM_H

typedef enum{
	Button = 0,
	HealthString = 1,
	AttackString = 2
} GUIObjectName;

const char * getGUIObjectName( int enumVal );
#endif