#ifndef _DIRECTINPUT_H
#define _DIRECTINPUT_H

#define DIRECTINPUT_VERSION 0x0800

#include <stdbool.h>
#include <stdio.h>
#include <dinput.h>

void DInputInit(HINSTANCE hinst, HWND hwnd);
void DInputGetKeys(void);

byte deviceState[256];

#endif