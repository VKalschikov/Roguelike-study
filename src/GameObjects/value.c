#include <stdlib.h>

#include "value.h"
#include "Enums/valuesenum.h"

Value *createValue(ValueName nameOfValue, int value)
{
	Value *v = (Value*)malloc(sizeof(Value));
	v->value = value;
	v->nameOfValue = nameOfValue;
	return v;
}
void v_destroy(Value *v)
{
	free(v);
}