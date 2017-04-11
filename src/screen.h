#ifndef SCREEN_H
#define SCREEN_H

typedef struct{
	void (*draw)(void *ptr);
} Screen;

Screen *screen_createScreen(void (*drawFunc)(void *ptr));

#endif