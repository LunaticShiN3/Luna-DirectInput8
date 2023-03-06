// dllmain.c : Defines the entry point for the DLL application.
#include "pch.h"

#define PLUGIN_NAME "Luna's DirectInput8"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_NAMEVER PLUGIN_NAME " v" PLUGIN_VERSION
#define PLUGIN_REPO "https://github.com/LunaticShiN3/Luna's_DirectInput8"
#define DIRECTINPUT_VERSION 0x0800

#include "zilmar_controller_1.0.h"
#include <dinput.h>

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
        "DirectInput8 plugin designed as a Jabo alternative for keyboard players\n"
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

/*EXPORT void CALL GetKeys(int Control, BUTTONS* Keys) {
    //stuff here later
}*/

EXPORT void CALL RomClosed(void) {
    //required for PJ64 2.x and newer
}

EXPORT void CALL RomOpen(void) {
    //stuff here later
}

/*EXPORT void CALL WM_KeyDown(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}

EXPORT void CALL WM_KeyUp(WPARAM wParam, LPARAM lParam) {
    //stuff here later
}*/