#ifndef VALUE_H
#define VALUE_H

typedef struct{
	int value;
	const char *nameOfValue;
} Value;

Value *createValue(int value, const char *nameOfValue);
void v_destroy(Value *v);

#endif