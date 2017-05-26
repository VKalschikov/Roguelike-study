#ifndef VALUESVECTORECTOR_H
#define VALUESVECTORECTOR_H

#include "../value.h"
#include "../Enums/valuesenum.h"

typedef struct{
	int maxAmount;
	int currentAmount;
	Value **values;
} ValuesVector;

ValuesVector *createValuesVector();

void vv_add(ValuesVector *vv, Value *v);
void vv_removeI(ValuesVector *vv, int index);
void vv_removeV(ValuesVector *vv, Value *v);
int vv_find(ValuesVector *vv, Value *v);
void vv_increaseMemory(ValuesVector *vv);
void vv_decreaseMemory(ValuesVector *vv);
Value *vv_get(ValuesVector *vv, int index);
Value *vv_getByEnumName(ValuesVector *vv, ValueName name);
void vv_destroy(ValuesVector *vv);

#endif