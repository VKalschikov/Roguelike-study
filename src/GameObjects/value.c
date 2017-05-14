#include <stdlib.h>

#include "value.h"

Value *createValue(int value, const char *nameOfValue)
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