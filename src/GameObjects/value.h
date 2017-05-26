#ifndef VALUE_H
#define VALUE_H

#include "Enums/valuesenum.h"

typedef struct{
	int value;
	ValueName nameOfValue;
} Value;

Value *createValue(ValueName nameOfValue, int value);
void v_destroy(Value *v);

#endif