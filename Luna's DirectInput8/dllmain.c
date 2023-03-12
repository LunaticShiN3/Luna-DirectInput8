// dllmain.c : Defines the entry point for the DLL application.
#include "pch.h"

#define PLUGIN_NAME "Luna's DirectInput8"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_NAMEVER PLUGIN_NAME " v" PLUGIN_VERSION
#define PLUGIN_REPO "https://github.com/LunaticShiN3/Luna-DirectInput8"

#include "zilmar_controller_1.0.h"
#include "directinput.h"

HMODULE hModuleVariable;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    hModuleVariable = hModule;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

EXPORT void CALL CloseDLL(void) {
    //stuff here later
}

EXPORT void CALL DllAbout(HWND hParent)
{
    MessageBoxA(
        hParent,
        "DirectInput8 plugin designed as a Jabo alternative for keyboard\n"
        "Made by ShiN3\n"
        "Version " PLUGIN_VERSION "\n"
        "Compiled on " __DATE__ "\n\n"
        PLUGIN_REPO,
        "About " PLUGIN_NAMEVER,
        MB_OK | MB_ICONINFORMATION
    );
}

EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo) {
    PluginInfo->Version = 0x0100;
    PluginInfo->Type = PLUGIN_TYPE_CONTROLLER;
    strncpy_s(
        PluginInfo->Name,
        sizeof(PluginInfo->Name),
        PLUGIN_NAMEVER,
        sizeof(PluginInfo->Name)
    );
}


static byte keybindDpadRight = 0x27; //Ñ
static byte keybindDpadLeft = 0x26; //L
static byte keybindDpadDown = 0x34; //.
static byte keybindDpadUp = 0x19; //P
static byte keybindStart = 0x1C; //Enter
static byte keybindZ = 0x2C; //Z
static byte keybindB = 0x2E; //C
static byte keybindA = 0x2D; //X
static byte keybindCRight = 0x4D; //Numpad6
static byte keybindCLeft = 0x4B; //Numpad4
static byte keybindCDown = 0x50; //Numpad2
static byte keybindCUp = 0x48; //Numpad8
static byte keybindR = 0x1F; //S
static byte keybindL = 0x1E; //A

static byte keybindRight = 0xCD; //Right arrow key
static byte keybindLeft = 0xCB; //Left arrow key
static byte keybindDown = 0xD0; //Down arrow key
static byte keybindUp = 0xC8; //Up arrow key

static byte rangeCardinalX = 126;
static byte rangeCardinalY = 126; //These need to be limited to 127 max.
static byte rangeDiagonalX = 90;
static byte rangeDiagonalY = 89;

byte integerX;
byte integerY;

float floatX;
float floatY;

typedef struct Modifier {
    byte keybind;
    float multiplierX;
    float multiplierY;
} Modifier;

struct Modifier modifiers[50];

Modifier modifers[50] = {
  {0x2A, 0.2, 0.2},
  {0x39, 0.87, 0.5},
  {0x2F, 0.5, 0.87}
};

EXPORT void CALL GetKeys(int Control, BUTTONS* Keys) {
    DInputGetKeys();
    Keys->R_DPAD = (deviceState[keybindDpadRight] >> 7);
    Keys->L_DPAD = (deviceState[keybindDpadLeft] >> 7);
    Keys->D_DPAD = (deviceState[keybindDpadDown] >> 7);
    Keys->U_DPAD = (deviceState[keybindDpadUp] >> 7);
    Keys->START_BUTTON = (deviceState[keybindStart] >> 7);
    Keys->Z_TRIG = (deviceState[keybindZ] >> 7);
    Keys->B_BUTTON = (deviceState[keybindB] >> 7);
    Keys->A_BUTTON = (deviceState[keybindA] >> 7);
    Keys->R_CBUTTON = (deviceState[keybindCRight] >> 7);
    Keys->L_CBUTTON = (deviceState[keybindCLeft] >> 7);
    Keys->D_CBUTTON = (deviceState[keybindCDown] >> 7);
    Keys->U_CBUTTON = (deviceState[keybindCUp] >> 7);
    Keys->R_TRIG = (deviceState[keybindR] >> 7);
    Keys->L_TRIG = (deviceState[keybindL] >> 7);

    if (deviceState[keybindLeft] >> 7) {
        integerX = -1;
    }
    else if (deviceState[keybindRight] >> 7) {
        integerX = 1;
    }
    else {
        integerX = 0;
    }
    if (deviceState[keybindDown] >> 7) {
        integerY = -1;
    }
    else if (deviceState[keybindUp] >> 7) {
        integerY = 1;
    }
    else {
        integerY = 0;
    }

    if (integerX != 0 && integerY != 0) {
        Keys->Y_AXIS = integerX * rangeDiagonalX;
        Keys->X_AXIS = integerY * rangeDiagonalY;
    }
    else {
        Keys->Y_AXIS = integerX * rangeCardinalX;
        Keys->X_AXIS = integerY * rangeCardinalY;
    }

    for (int i = 0; i < sizeof(modifiers) / sizeof(Modifier); i++) {
        if (deviceState[modifiers[i].keybind] >> 7) {
            Keys->Y_AXIS *= modifiers[i].multiplierX; //X and Y axis are swapped because of course they are????
            Keys->X_AXIS *= modifiers[i].multiplierY;
        }
    }
}

EXPORT void CALL InitiateControllers(HWND hMainWindow, CONTROL Controls[4])
{
    for (int i = 0; i < 4; ++i)
    {
        Controls[i].Present = FALSE; //Enables controller 1 only. Might change later.
        Controls[i].RawData = FALSE;
    }
    Controls[0].Present = TRUE;
}

EXPORT void CALL RomClosed(void) {
    //required for PJ64 2.x and newer
}

EXPORT void CALL RomOpen(void) {
    HWND activeWindow = GetActiveWindow();
    DInputInit(hModuleVariable, activeWindow);
}

/*EXPORT void CALL WM_KeyDown(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}

EXPORT void CALL WM_KeyUp(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}*/