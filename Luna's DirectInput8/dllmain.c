// dllmain.c : Defines the entry point for the DLL application.
#include "pch.h"

#define PLUGIN_NAME "Luna's DirectInput8"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_NAMEVER PLUGIN_NAME " v" PLUGIN_VERSION
#define PLUGIN_REPO "https://github.com/LunaticShiN3/Luna-DirectInput8"

#include "zilmar_controller_1.0.h"
#include "directinput.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
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

EXPORT void CALL GetKeys(int Control, BUTTONS* Keys) {
    Keys->R_DPAD = DInputGetKey(keybindDpadRight);
    Keys->L_DPAD = DInputGetKey(keybindDpadLeft);
    Keys->D_DPAD = DInputGetKey(keybindDpadDown);
    Keys->U_DPAD = DInputGetKey(keybindDpadUp);
    Keys->START_BUTTON = DInputGetKey(keybindStart);
    Keys->Z_TRIG = DInputGetKey(keybindZ);
    Keys->B_BUTTON = DInputGetKey(keybindB);
    Keys->A_BUTTON = DInputGetKey(keybindA);
    Keys->R_CBUTTON = DInputGetKey(keybindCRight);
    Keys->L_CBUTTON = DInputGetKey(keybindCLeft);
    Keys->D_CBUTTON = DInputGetKey(keybindCDown);
    Keys->U_CBUTTON = DInputGetKey(keybindCUp);
    Keys->R_TRIG = DInputGetKey(keybindR);
    Keys->L_TRIG = DInputGetKey(keybindL);
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
    void DInputInit(hModule);
}

/*EXPORT void CALL WM_KeyDown(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}

EXPORT void CALL WM_KeyUp(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}*/