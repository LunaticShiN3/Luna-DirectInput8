#ifndef _DIRECTINPUT_H
#define _DIRECTINPUT_H

#define DIRECTINPUT_VERSION 0x0800

#include <stdbool.h>
#include <dinput.h>

void DInputInit(HINSTANCE hinst, HWND hwnd);
unsigned DInputGetKey(byte KeyCode);

#endif