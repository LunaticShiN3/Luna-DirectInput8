#include "pch.h"
#include "config.h"

typedef struct
{
    const enum { CONF_INT, CONF_BYTE, CONF_FLOAT } type;
    void const* ptr;
    const char* name;
} conf_data_t;

static conf_data_t conf_data[] =
{
    {CONF_INT, &config.configVersion, "Config_Version"},

    {CONF_BYTE, &config.keybindDpadRight, "DPad_Right"},
    {CONF_BYTE, &config.keybindDpadLeft, "DPad_Left"},
    {CONF_BYTE, &config.keybindDpadDown, "DPad_Down"},
    {CONF_BYTE, &config.keybindDpadUp, "DPad_Up"},
    {CONF_BYTE, &config.keybindStart, "Start"},
    {CONF_BYTE, &config.keybindZ, "Z"},
    {CONF_BYTE, &config.keybindB, "B"},
    {CONF_BYTE, &config.keybindA, "A"},
    {CONF_BYTE, &config.keybindCRight, "C_Right"},
    {CONF_BYTE, &config.keybindCLeft, "C_Left"},
    {CONF_BYTE, &config.keybindCDown, "C_Down"},
    {CONF_BYTE, &config.keybindCUp, "C_Up"},
    {CONF_BYTE, &config.keybindR, "R"},
    {CONF_BYTE, &config.keybindL, "L"},

    {CONF_BYTE, &config.keybindRight, "Analog_Right"},
    {CONF_BYTE, &config.keybindLeft, "Analog_Left"},
    {CONF_BYTE, &config.keybindDown, "Analog_Down"},
    {CONF_BYTE, &config.keybindUp, "Analog_Up"},

    {CONF_BYTE, &config.rangeCardinalX, "Cardinal_Range_X"},
    {CONF_BYTE, &config.rangeCardinalY, "Cardinal_Range_Y"},
    {CONF_BYTE, &config.rangeDiagonalX, "Diagonal_Range_X"},
    {CONF_BYTE, &config.rangeDiagonalY, "Diagonal_Range_Y"},

};