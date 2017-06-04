#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "toolfuncs.h"

void fatal(char *message){
	char errorMessage[100];

	strcpy(errorMessage, "[!!] Fatal Error ");
	strncat(errorMessage, message, 83);
	perror(errorMessage);
	exit(-1);
}

void debug(char *message)
{
	printf("%s\n", message);
}