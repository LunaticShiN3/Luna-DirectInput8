
#include "pch.h"
#include "directinput.h"

IDirectInput8* interfacePointer;
LPDIRECTINPUTDEVICE8 lpdiKeyboard;
byte deviceState[256];

void DInputInit(HINSTANCE hinst) {
	HRESULT result= DirectInput8Create( //Creates a DirectInput8 object.
		hinst, //this has to be hModule
		DIRECTINPUT_VERSION,
		&IID_IDirectInput8A,
		(LPVOID*)&interfacePointer,
		NULL
	);

	interfacePointer->CreateDevice( //Creates a keyboard DirectInput device.
		&GUID_SysKeyboard,
		&lpdiKeyboard,
		NULL
	);

	lpdiKeyboard->SetCooperativeLevel(hwnd, //Sets cooperative level. Nonexclusive, no background input. Might add settings later. Figure out how to set hwnd https://learn.microsoft.com/en-us/previous-versions/windows/desktop/ee416848(v=vs.85)?
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND); //Add DISCL_NOWINKEY next to exclusivity to disable Windows key.

	result= lpdiKeyboard->SetDataFormat(c_dfDIKeyboard); //Sets data format

	result= lpdiKeyboard->Acquire(); //Acquires input device
}

unsigned DInputGetKey(byte KeyCode) {
	HRESULT result= lpdiKeyboard->GetDeviceState((sizeof(deviceState)), (LPVOID*)&deviceState);
	return (deviceState[KeyCode] >> 7);
}