#include "gameobject.h"
#include "Vectors/valuesvector.h"
#include "value.h"
#include "Enums/gameobjectsenum.h"
#include <stdlib.h>
#include <string.h>

GameObject *createGameObject(GameObjectName type, int number, ValuesVector *values, int xPos, int yPos)
{
	GameObject *go = (GameObject*)malloc(sizeof(GameObject));
	go->typeOfObject = type;
	go->numberOfValues = number;
	go->valuesVector = values;
	go->xPos = xPos;
	go->yPos = yPos;
	return go;
}

void go_setValue(GameObject *go, ValueName name, int value)
{
	Value *temp =  vv_getByEnumName(go->valuesVector, name);
	if(temp!=NULL)
		temp->value = value;
}
int go_getValue(GameObject *go, ValueName name)
{
	Value *temp =  vv_getByEnumName(go->valuesVector, name);
	if(temp!=NULL)
		return temp->value;
	return 0;
}

void go_destroy(GameObject *go)
{
	if(go->valuesVector!= (ValuesVector*)0)
		vv_destroy(go->valuesVector);
	free(go);
}	

GameObject *createWall(int xPos, int yPos)
{
	return createGameObject(Wall,0,(ValuesVector*)0,xPos,yPos);
}
GameObject *createFloor(int xPos, int yPos)
{
	return createGameObject(Floor,0,(ValuesVector*)0,xPos,yPos);
}

GameObject *createPlayer(int xPos, int yPos, CharacterClass charClass)
{
	ValuesVector *vv = createValuesVector();
	vv_add(vv, createValue(Class, charClass));
	vv_add(vv, createValue(Health, 100));
	vv_add(vv, createValue(Attack, 5));
	vv_add(vv, createValue(IsPlayer, 1));
	return createGameObject(Player, 4, vv, xPos, yPos);
}