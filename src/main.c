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
		}
		if(isDestroy)
			break;
		if(gameEvent !=null)
		{
			sfRenderWindow_clear(window, sfBlack);
			gh_gameCycle(gHandler, goinfo, gameEvent);
			drawer_draw(drawer, window, gHandler->currentScreen);
			sfSleep(sfSeconds(0.2));
		}
		sfRenderWindow_display(window);
	}

	return 0;
}

void initialize(GameHandler **gHandler, Drawer **drawer, GameObjectsInfo **goinfo)
{
	printf("Initialize\n");
	(*goinfo) = createGameObjectsInfo(1);
	(*drawer) = createDrawer(*goinfo);
	int numberOfScreens = (*goinfo)->numberOfScreens;

	Screen **screenes =(Screen**)malloc(sizeof(Screen*)*numberOfScreens);
	screenes[0] = createGameScreen(0);
	(*gHandler) = createGameHandler(1, 0, screenes, *goinfo);
}