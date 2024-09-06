#pragma once

enum ysaren_layers {
    L_BASE = 0,
    L_QWERTY = 0,

    L_GAME_HW,

    L_SYMBOLS,
    L_NAVIGATION,
    L_SWITCH,
    L_NUMBERS,
    L_NUMPAD,
    L_MEDIA,

    L_IDE,

    _LAYER_SAFE_RANGE
};

struct Layer {
    int layer;
    char *name;
    bool inverted;
};

struct Layer layers[] = {
    {L_QWERTY,     "Qwrt ", false},
    {L_GAME_HW,    "Hero ", true },
    {L_SYMBOLS,    "Symb ", false},
    {L_NAVIGATION, "Navi ", false},
    {L_SWITCH,     "Swit ", false},
    {L_NUMBERS,    "Num  ", false},
    {L_NUMPAD,     "N-pad", false},
    {L_MEDIA,      "Media", false},
    {L_IDE,        "IDE  ", false},
};

#define LAYERS_COUNT 9
