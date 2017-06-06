#include <stdlib.h>
#include <stdio.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>

#include "GraphicsEngine/drawer.h"
#include "GameHandler/gamehandler.h"
#include "GameHandler/Screens/screens.h"
#include "GameHandler/screen.h"
#include "GameObjects/gameobjectsinfo.h"
#include "Tools/toolfuncs.h"
#include "enums.h"


void initialize(GameHandler **gHandler, Drawer **drawer, GameObjectsInfo **goinfo);

int main(){

	printf("StartGame\n");

	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	sfEvent event;

	GameObjectsInfo *goinfo;
	GameHandler *gHandler;
	Drawer *drawer;

	initialize(&gHandler, &drawer, &goinfo);

	Event gameEvent;

	window = sfRenderWindow_create(mode, "Roguelike", sfClose, NULL);
	if(!window)
		fatal("in main() while create window");
	
	sfRenderWindow_clear(window, sfBlack);
	drawer_draw(drawer, window, gHandler->currentScreen);
	while (sfRenderWindow_isOpen(window))
	{
		gameEvent = null;
		int isDestroy = 0;
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
                 sfRenderWindow_close(window);
                 gh_destroy(gHandler);
                 drawer_destroy(drawer);
                 goi_destroy(goinfo);
                 isDestroy = 1;
			}

            if(sfKeyboard_isKeyPressed(sfKeyW))
            {
            	gameEvent = pressKeyUp;
            }
            if(sfKeyboard_isKeyPressed(sfKeyD))
            {
            	gameEvent = pressKeyRight;
            }
            if(sfKeyboard_isKeyPressed(sfKeyS))
            {
            	gameEvent = pressKeyDown;
            }
            if(sfKeyboard_isKeyPressed(sfKeyA))
            {
            	gameEvent = pressKeyLeft;
            }
            if(sfKeyboard_isKeyPressed(sfKeySpace))
            {
            	gameEvent = pressSpace;
            }
		}
		if(isDestroy)
			break;
		if(gameEvent !=null)
		{
			sfRenderWindow_clear(window, sfBlack);
			if(!gh_gameCycle(gHandler, goinfo, gameEvent))
				break;
			drawer_draw(drawer, window, gHandler->currentScreen);
			sfSleep(sfSeconds(0.1));
		}
		sfRenderWindow_display(window);
	}

	return 0;
}

void initialize(GameHandler **gHandler, Drawer **drawer, GameObjectsInfo **goinfo)
{
	printf("Initialize\n");
	(*goinfo) = createGameObjectsInfo(2);
	(*drawer) = createDrawer(*goinfo);
	int numberOfScreens = (*goinfo)->numberOfScreens;

	Screen **screenes =(Screen**)malloc(sizeof(Screen*)*numberOfScreens);
	screenes[0] = createGameScreen(0);
	screenes[1] = createGameOverScreen(1);
	(*gHandler) = createGameHandler(2, 0, screenes, *goinfo);
}