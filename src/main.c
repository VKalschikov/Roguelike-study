#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.h>

#include "game.h"
#include "screen.h"
#include "mainMenuScreen.h"
#include "gameScreen.h"


int main(){

	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	sfEvent event;


	window = sfRenderWindow_create(mode, "Rogue-like", sfClose, NULL);
	if(!window)
		return 1;

	Game *game = g_createGame();

	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}

	sfRenderWindow_destroy(window);

	g_changeScreen(game,screen_createScreen(MainMenuScreen));
	g_drawScreen(game);
	g_drawScreen(game);


	g_destroy(game);

	return 0;
}

