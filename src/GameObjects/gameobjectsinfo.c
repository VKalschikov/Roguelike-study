#include <stdlib.h>

#include "gameobjectsinfo.h"
#include "Vectors/gameobjectsvector.h"
#include "Vectors/guiobjectsvector.h"

GameObjectsInfo *createGameObjectsInfo(int numberOfScreens)
{
	GameObjectsInfo *goi = (GameObjectsInfo*)malloc(sizeof(GameObjectsInfo));
	goi->numberOfScreens = numberOfScreens;
	goi->staticGameObjects = (GameObjectsVector**)malloc(sizeof(GameObjectsVector)*numberOfScreens);
	goi->dynamicGameObjects = (GameObjectsVector**)malloc(sizeof(GameObjectsVector)*numberOfScreens);
	goi->GUIObjects = (GUIObjectsVector**)malloc(sizeof(GUIObjectsVector)*numberOfScreens);
	for(int i=0;i<numberOfScreens;i++)
	{
		goi->staticGameObjects[i] = creatGameObjectsVector();
		goi->dynamicGameObjects[i] = creatGameObjectsVector();
		goi->GUIObjects[i] = creatGUIObjectsVector();
	}
	return goi;
}

void goi_destroy(GameObjectsInfo *goi)
{
	for(int i=0;i<goi->numberOfScreens;i++)
	{
		gov_destroy(goi->staticGameObjects[i]);
		gov_destroy(goi->dynamicGameObjects[i]);
		guiov_destroy(goi->GUIObjects[i]);
	}
	free(goi->staticGameObjects);
	free(goi->dynamicGameObjects);
	free(goi->GUIObjects);
	free(goi);
}