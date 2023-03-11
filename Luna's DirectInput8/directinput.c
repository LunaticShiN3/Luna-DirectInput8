
#include "pch.h"
#include "directinput.h"

IDirectInput8A* interfacePointer;
LPDIRECTINPUTDEVICE8A lpdiKeyboard;
byte deviceState[256];

void DInputInit(HINSTANCE hinst, HWND hwnd) {
	HRESULT result= DirectInput8Create( //Creates a DirectInput8 object.
		hinst, //this has to be hModule
		DIRECTINPUT_VERSION,
		&IID_IDirectInput8A,
		(LPVOID*)&interfacePointer,
		NULL
	);

	IDirectInput8_CreateDevice( //Creates a keyboard DirectInput device.
		interfacePointer,
		&GUID_SysKeyboard,
		&lpdiKeyboard,
		NULL
	);

	IDirectInputDevice8_SetCooperativeLevel(lpdiKeyboard, hwnd, //Sets cooperative level. Nonexclusive, no background input. Might add settings later. Figure out how to set hwnd https://learn.microsoft.com/en-us/previous-versions/windows/desktop/ee416848(v=vs.85)?
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND); //Add DISCL_NOWINKEY next to exclusivity to disable Windows key.

	result= IDirectInputDevice8_SetDataFormat(lpdiKeyboard, &c_dfDIKeyboard); //Sets data format

	result= IDirectInputDevice8_Acquire(lpdiKeyboard); //Acquires input device
}

unsigned DInputGetKey(byte KeyCode) {
	HRESULT result= IDirectInputDevice8_GetDeviceState(lpdiKeyboard, (sizeof(deviceState)), (LPVOID*)&deviceState);
	return (deviceState[KeyCode] >> 7);
}