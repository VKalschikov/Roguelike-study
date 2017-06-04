#include <stdlib.h>
#include <stdio.h>

#include "valuesvector.h"
#include "../../enums.h"
#include "../value.h"

#define STD_AMOUNT_OF_VALUES 40


ValuesVector *createValuesVector()
{
	printf("Create ValuesVector\n");
	ValuesVector *vv = (ValuesVector*)malloc(sizeof(ValuesVector));
	vv->maxAmount = STD_AMOUNT_OF_VALUES ;
	vv->currentAmount = 0;
	vv->values = (Value**)malloc(sizeof(Value*)*vv->maxAmount);
	return vv;
}

void vv_add(ValuesVector *vv, Value *go)
{
	printf("VV ADD\n");
	if(vv->currentAmount == vv->maxAmount)
		vv_increaseMemory(vv);
	vv->values[vv->currentAmount] = go;
	vv->currentAmount++;
}

void vv_removeI(ValuesVector *vv, int index)
{
	printf("VV REMOVE I\n");
	if(index<vv->currentAmount)
	{
		for(int i=index; i<vv->currentAmount-1; i++)
		{
			vv->values[i] = vv->values[i+1];
		}
		vv->values[vv->currentAmount-1]=NULL;
		vv->currentAmount--;
		if((vv->maxAmount-vv->currentAmount)>STD_AMOUNT_OF_VALUES +5)
			vv_decreaseMemory(vv);
	}
}

void vv_removeV(ValuesVector *vv, Value *go)
{
	printf("VV REMOVE V\n");
	int index = vv_find(vv, go);
	if(index!=-1)
	{
		vv_removeI(vv, index);
	}
}

int vv_find(ValuesVector *vv, Value *go)
{
	printf("VV FIND\n");
	int index = -1;
	for(int i=0;i<vv->currentAmount;i++)
	{
		if(go==vv->values[i])
		{
			index = i;
		}
	}
	return index;
}

void vv_increaseMemory(ValuesVector *vv)
{
	printf("VV IM\n");
	Value **newA = (Value**)malloc(sizeof(Value*)*vv->maxAmount+STD_AMOUNT_OF_VALUES );
	for(int i=0;i<vv->currentAmount;i++)
	{
		newA[i] = vv->values[i];
	}
	free(vv->values);
	vv->values = newA;
	vv->maxAmount+=STD_AMOUNT_OF_VALUES ;
}

void vv_decreaseMemory(ValuesVector *vv)
{
	printf("VV DM\n");
	Value **newA = (Value**)malloc(sizeof(Value*)*vv->maxAmount-STD_AMOUNT_OF_VALUES );
	for(int i=0;i<vv->currentAmount;i++)
	{
		newA[i] = vv->values[i];
	}
	free(vv->values);
	vv->values = newA;
	vv->maxAmount-= STD_AMOUNT_OF_VALUES ;
}

Value *vv_get(ValuesVector *vv, int index)
{
	printf("VV GET\n");
	return vv->values[index];
}

Value *vv_getByEnumName(ValuesVector *vv, ValueName name)
{
	printf("VV GET BEN\n");
	for(int i=0;i<vv->currentAmount;i++)
	{
		if(name == vv->values[i]->nameOfValue)
		{
			return vv->values[i];
		}
	}
	return NULL;
}

void vv_destroy(ValuesVector *vv)
{
	printf("VV Destroy\n");
	for(int i=0;i<vv->currentAmount;i++)
		free(vv->values[i]);
	free(vv);
}