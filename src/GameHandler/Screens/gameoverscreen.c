#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gameoverscreen.h"

#include "../screen.h"
#include "../../vectors.h"

Screen *createGameOverScreen(int numberOfScreen)
{
	ScreenInfo *si = createScreenInfo(gos_initializeFunc, gos_updateFunc, gos_destroy, NULL);
	return createScreen(si, numberOfScreen);
}

int gos_updateFunc(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues,
		Event gameEvent
		)
{
	if(gameEvent == pressSpace)
		return -1;
	else
		return 0;
}
void gos_initializeFunc(
	GameObjectsVector *staticgo,
	GameObjectsVector *dynamicgo,
	GUIObjectsVector *guio,		
	void *uniqueValues
	)
{
	printf("GameOverInitialize\n");
	staticgo = gov_clear(staticgo);
	dynamicgo = gov_clear(dynamicgo);
	guio = guiov_clear(guio);
	GUIObject *ooo = createGUIObject(GameOverString, 120, 200, (char*)malloc(sizeof(char)*50));
	guiov_add(guio, ooo);
	strcpy(ooo->object,"GAME OVER PRESS SPACE TO RESTART");
}
void gos_destroy(
		GameObjectsVector *staticgo,
		GameObjectsVector *dynamicgo,
		GUIObjectsVector *guio,		
		void *uniqueValues
		)
{
	gov_destroy(staticgo);
	gov_destroy(dynamicgo);
	guiov_destroy(guio);
	free(uniqueValues);
}