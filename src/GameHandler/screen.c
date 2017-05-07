#include <stdlib.h>
#include "screen.h"

#include "controller.h"
#include "screeninfo.h"

Screen *createScreen(ScreenInfo *si)
{
	Screen *screen = (Screen*)malloc(sizeof(Screen));
	screen->controller = createController(si);
	return screen;
}

void s_initialize(Screen *screen, GameObject *gameObjects, GUIObject *guiObjects)
{
	c_initialize(screen->controller, gameObjects, guiObjects);
}
int s_update(Screen *screen, GameObject *gameObjects, GUIObject *guiObjects)
{
	return c_update(scren->controller, gameObjects, guiObjects);
}
void s_destroy(Screen *screen)
{
	c_destroy(screen->controller);
	free(scren);
}