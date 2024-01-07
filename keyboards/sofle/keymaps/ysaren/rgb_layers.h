#pragma once

// colour palette

#define DHUSAR_GREY              0,   0, 171 //#AAAAAA
#define CEREBRAL_GREY            0,   0, 204 //#CCCCCC
#define SUGAR_GRAPE            192, 204, 255 //#9933FF
#define BUDDHAS_LOVE_HANDLES    28, 204, 255 //#FFBB33
#define ALIEN_PARASITE          81, 204, 255 //#47FF33
#define BIG_YELLOW_TAXI         43, 204, 255 //#FFFF33
#define DODGER_BLUE            153, 204, 255 //#3388FF
#define BRIGHT_ORANGE           12, 204, 255 //#FF6D33

// unused
#define HSV_VIBRANT_BLUE         159, 255,  63 //224, 100, 100 // #003FFA
#define HSV_THE_GRAPE_WAR_OF_97  199, 255,  63 //282, 100, 100 // #B400FF
#define HSV_CADMIUM_YELLOW        41, 255,  63 // 57, 100, 100 // #FFF500
#define HSV_DEEP_GREEN            85, 255,  63 //120, 100, 100 // #00FF00
#define HSV_GRAY                   0,   0,  63
#define HSV_GIANTS_ORANGE         11, 255, 255 // 15,  88, 100 // #FF571E

// funcitonal colours
#define HSV_ALPHAS DHUSAR_GREY
#define HSV_ALPHAS_ACCENT CEREBRAL_GREY
#define HSV_MODS SUGAR_GRAPE
#define HSV_LAYER_SWITCH BUDDHAS_LOVE_HANDLES
#define HSV_NUMBERS BIG_YELLOW_TAXI
#define HSV_NAVIGATION DODGER_BLUE
#define HSV_FUNCTION ALIEN_PARASITE
#define HSV_SPECIAL BRIGHT_ORANGE


#define L_HAND 0
#define R_HAND L_HAND + 35

// Light combinations
#define SET_ALL(...) \
    {0, 2 * 35, __VA_ARGS__}

#define SET_LAYER_SWITCHERS(...) \
    {L_HAND + 26, 1, __VA_ARGS__}, \
    {R_HAND + 26, 1, __VA_ARGS__}

#define SET_UNDERGLOW(...) \
    {L_HAND + 0, 6, __VA_ARGS__}, \
    {R_HAND + 0, 6, __VA_ARGS__}

#define SET_NUMBER(...) \
    {L_HAND + 13, 1, __VA_ARGS__}, \
    {L_HAND + 18, 1, __VA_ARGS__}, \
    {L_HAND + 23, 1, __VA_ARGS__}, \
    {L_HAND + 28, 1, __VA_ARGS__}, \
    {L_HAND + 33, 1, __VA_ARGS__}, \
    {R_HAND + 13, 1, __VA_ARGS__}, \
    {R_HAND + 18, 1, __VA_ARGS__}, \
    {R_HAND + 23, 1, __VA_ARGS__}, \
    {R_HAND + 28, 1, __VA_ARGS__}, \
    {R_HAND + 33, 1, __VA_ARGS__}

#define SET_NUMPAD(...) \
    {R_HAND + 15, 5, __VA_ARGS__}, \
    {R_HAND + 22, 3, __VA_ARGS__}, \
    {R_HAND + 27, 3, __VA_ARGS__}

#define SET_NUMROW(...) \
    {L_HAND + 10, 2, __VA_ARGS__}, \
    {R_HAND + 10, 2, __VA_ARGS__}, \
    {L_HAND + 20, 2, __VA_ARGS__}, \
    {R_HAND + 20, 2, __VA_ARGS__}, \
    {L_HAND + 30, 2, __VA_ARGS__}, \
    {R_HAND + 30, 2, __VA_ARGS__}

#define SET_INNER_COL(...) \
    {L_HAND + 33, 4, __VA_ARGS__}, \
    {R_HAND + 33, 4, __VA_ARGS__}

#define SET_OUTER_COL(...) \
    {L_HAND + 7, 4, __VA_ARGS__}, \
    {R_HAND + 7, 4, __VA_ARGS__}


#define SET_THUMB_CLUSTER(...) \
    {L_HAND + 25, 2, __VA_ARGS__}, \
    {R_HAND + 25, 2, __VA_ARGS__}

#define SET_BOTTOM_MODIFIERS(...) \
    {L_HAND + 6, 1, __VA_ARGS__}, \
    {R_HAND + 6, 1, __VA_ARGS__}, \
    {L_HAND + 15, 2, __VA_ARGS__}, \
    {R_HAND + 15, 2, __VA_ARGS__}

#define SET_NON_CORNE_LIGHTS(...) \
    SET_NUMROW(__VA_ARGS__), \
    {L_HAND + 6, 1, __VA_ARGS__}, \
    {R_HAND + 6, 1, __VA_ARGS__}, \
    {L_HAND + 15, 1, __VA_ARGS__}, \
    {R_HAND + 15, 1, __VA_ARGS__}

#define SET_LAYER_ID(...)     \
    SET_UNDERGLOW(__VA_ARGS__), \
    SET_BOTTOM_MODIFIERS(__VA_ARGS__), \
    SET_OUTER_COL(__VA_ARGS__), \
    SET_THUMB_CLUSTER(__VA_ARGS__), \
    SET_LAYER_SWITCHERS(HSV_LAYER_SWITCH)

/*
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 10 11 20 21 30 31       31 30 21 20 11 10  0
  //    00    01    02       00    01    02
  // 09 12 19 22 29 32       32 29 22 19 12 09  1
  //
  // 08 13 18 23 28 33       33 28 23 18 13 08  2
  //
  // 07 14 17 24 27 34       34 27 24 17 14 07  3
  //
  //     06 15 16 25 26     26 25 16 15 06      4
  //    05    04    03       03    04    05

*/
