#ifndef VALUE_H
#define VALUE_H

#include "../enums.h"

typedef struct{
	int value;
	ValueName nameOfValue;
} Value;

Value *createValue(ValueName nameOfValue, int value);
void v_destroy(Value *v);

#endif