#include "dllmain.c"
#include "directinput.h"

#define DIRECTINPUT_VERSION 0x0800

HRESULT DirectInput8Create( //Creates a DirectInput8 object.
	hModule,
	DIRECTINPUT_VERSION,
	IID_IDirectInput8A,
	&(*interfacePointer),
	NULL
);

LPDIRECTINPUTDEVICE8  lpdiKeyboard; //Creates a keyboard DirectInput device.
interfacePointer->CreateDevice(GUID_SysKeyboard, &lpdiKeyboard, NULL);