#include "pch.h"
#include "directinput.h"

IDirectInput8A* interfacePointer;
LPDIRECTINPUTDEVICE8A lpdiKeyboard;
FILE* fptr;
errno_t err;

void DInputInit(HINSTANCE hinst, HWND hwnd) {
	err = fopen_s(&fptr, "C:\\Users\\Shuri\\Documents\\Project64 3.0\\Project64 3.0.1-N-v1\\Logs\\Lunalog.txt", "w");

	HRESULT result= DirectInput8Create( //Creates a DirectInput8 object.
		hinst, //this has to be hModule
		DIRECTINPUT_VERSION,
		&IID_IDirectInput8A,
		(LPVOID*)&interfacePointer,
		NULL
	);

	switch (result) {
		case DI_OK:
			fprintf(fptr, "DirectInput8Create DI_OK\n");
			break;
		case DIERR_BETADIRECTINPUTVERSION:
			fprintf(fptr, "DirectInput8Create DIERR_BETADIRECTINPUTVERSION\n");
			break;
		case DIERR_INVALIDPARAM:
			fprintf(fptr, "DirectInput8Create DIERR_INVALIDPARAM\n");
			break;
		case DIERR_OLDDIRECTINPUTVERSION:
			fprintf(fptr, "DirectInput8Create DIERR_OLDDIRECTINPUTVERSION\n");
			break;
		case DIERR_OUTOFMEMORY:
			fprintf(fptr, "DirectInput8Create DIERR_OUTOFMEMORY\n");
			break;
	}

	IDirectInput8_CreateDevice( //Creates a keyboard DirectInput device.
		interfacePointer,
		&GUID_SysKeyboard,
		&lpdiKeyboard,
		NULL
	);

	IDirectInputDevice8_SetCooperativeLevel(lpdiKeyboard, hwnd, //Sets cooperative level. Nonexclusive, no background input. Might add settings later. Figure out how to set hwnd https://learn.microsoft.com/en-us/previous-versions/windows/desktop/ee416848(v=vs.85)?
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND); //Add DISCL_NOWINKEY next to exclusivity to disable Windows key.

	result= IDirectInputDevice8_SetDataFormat(lpdiKeyboard, &c_dfDIKeyboard); //Sets data format

	switch (result) {
	case DI_OK:
		fprintf(fptr, "SetDataFormat DI_OK\n");
		break;
	case DIERR_ACQUIRED:
		fprintf(fptr, "SetDataFormat DIERR_ACQUIRED\n");
		break;
	case DIERR_INVALIDPARAM:
		fprintf(fptr, "SetDataFormat DIERR_INVALIDPARAM\n");
		break;
	case DIERR_NOTINITIALIZED:
		fprintf(fptr, "SetDataFormat DIERR_NOTINITIALIZED\n");
		break;
	}

	result= IDirectInputDevice8_Acquire(lpdiKeyboard); //Acquires input device

	switch (result) {
	case DI_OK:
		fprintf(fptr, "Acquire DI_OK\n");
		break;
	case DIERR_INVALIDPARAM:
		fprintf(fptr, "Acquire DIERR_INVALIDPARAM\n");
		break;
	case DIERR_NOTINITIALIZED:
		fprintf(fptr, "Acquire DIERR_NOTINITIALIZED\n");
		break;
	case DIERR_OTHERAPPHASPRIO:
		fprintf(fptr, "Acquire DIERR_OTHERAPPHASPRIO\n");
		break;
	}
	fflush(fptr);
	fclose(fptr);
}

void DInputGetKeys(byte KeyCode) {
	if (lpdiKeyboard != NULL) {
		HRESULT result = IDirectInputDevice8_GetDeviceState(lpdiKeyboard, (sizeof(deviceState)), (LPVOID*)&deviceState);
	}
}