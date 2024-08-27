#pragma once

// colour palette
// max brigtness is 120 (set in RGBLIGHT_LIMIT_VAL)

#define BASE_V 100

#define DHUSAR_GREY              0,   0, BASE_V //#AAAAAA
#define CEREBRAL_GREY            0,   0, BASE_V //#CCCCCC
#define SUGAR_GRAPE            192, 204, BASE_V //#9933FF
#define LILAS                  192, 104, BASE_V //#9933FF
#define BUDDHAS_LOVE_HANDLES    28, 204, BASE_V //#FFBB33
#define ALIEN_PARASITE          81, 204, BASE_V //#47FF33
#define BIG_YELLOW_TAXI         43, 204, BASE_V //#FFFF33
#define DODGER_BLUE            153, 204, BASE_V //#3388FF
#define APOCYAN                153, 102, BASE_V //#3388FF
#define BRIGHT_ORANGE           12, 204, BASE_V //#FF6D33

// unused
#define HSV_VIBRANT_BLUE         159, 255,  63 //224, 100, 100 // #003FFA
#define HSV_THE_GRAPE_WAR_OF_97  199, 255,  63 //282, 100, 100 // #B400FF
#define HSV_CADMIUM_YELLOW        41, 255,  63 // 57, 100, 100 // #FFF500
#define HSV_DEEP_GREEN            85, 255,  63 //120, 100, 100 // #00FF00
#define HSV_GRAY                   0,   0,  63
#define HSV_GIANTS_ORANGE         11, 255, 255 // 15,  88, 100 // #FF571E

// funcitonal colours
#define HSV_ALPHAS DHUSAR_GREY
#define HSV_ALPHAS_ACCENT LILAS
#define HSV_MODS SUGAR_GRAPE
#define HSV_LAYER_SWITCH BUDDHAS_LOVE_HANDLES
#define HSV_NUMBERS BIG_YELLOW_TAXI
#define HSV_NAVIGATION DODGER_BLUE
#define HSV_FUNCTION ALIEN_PARASITE
#define HSV_SPECIAL BRIGHT_ORANGE

#define LEDS_COUNT 35
#define L_HAND 0
#define R_HAND L_HAND + LEDS_COUNT

// Light combinations
#define SET_ALL(...) \
    {0, 2 * LEDS_COUNT, __VA_ARGS__}

#define SET_HAND(hand, ...) \
    {hand, LEDS_COUNT, __VA_ARGS__}

#define SET_LAYER_SWITCHERS(...) \
    {L_HAND + 26, 1, __VA_ARGS__}, \
    {R_HAND + 26, 1, __VA_ARGS__}

#define SET_UNDERGLOW(...) \
    {L_HAND + 0, 6, __VA_ARGS__}, \
    {R_HAND + 0, 6, __VA_ARGS__}

#define SET_ROW(hand, row, ...) \
    {hand + led_index[row][0], 1, __VA_ARGS__}, \
    {hand + led_index[row][1], 1, __VA_ARGS__}, \
    {hand + led_index[row][2], 1, __VA_ARGS__}, \
    {hand + led_index[row][3], 1, __VA_ARGS__}, \
    {hand + led_index[row][4], 1, __VA_ARGS__}, \
    {hand + led_index[row][5], 1, __VA_ARGS__}

#define SET_THUMB(hand, ...) \
    {hand + led_index[3][3], 1, __VA_ARGS__}, \
    {hand + led_index[3][4], 1, __VA_ARGS__}, \
    {hand + led_index[3][5], 1, __VA_ARGS__}

#define SET_ROW_0(...) \
    {L_HAND + 10, 2, __VA_ARGS__}, \
    {R_HAND + 10, 2, __VA_ARGS__}, \
    {L_HAND + 20, 2, __VA_ARGS__}, \
    {R_HAND + 20, 2, __VA_ARGS__}, \
    {L_HAND + 30, 2, __VA_ARGS__}, \
    {R_HAND + 30, 2, __VA_ARGS__}

#define SET_ROW_1(...) \
    {L_HAND + 12, 1, __VA_ARGS__}, \
    {L_HAND + 19, 1, __VA_ARGS__}, \
    {L_HAND + 22, 1, __VA_ARGS__}, \
    {L_HAND + 29, 1, __VA_ARGS__}, \
    {L_HAND + 32, 1, __VA_ARGS__}, \
    {R_HAND + 12, 1, __VA_ARGS__}, \
    {R_HAND + 19, 1, __VA_ARGS__}, \
    {R_HAND + 22, 1, __VA_ARGS__}, \
    {R_HAND + 29, 1, __VA_ARGS__}, \
    {R_HAND + 32, 1, __VA_ARGS__}

#define SET_ROW_2(...) \
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
    {L_HAND + 16, 1, __VA_ARGS__}, \
    {R_HAND + 16, 1, __VA_ARGS__}

    // {L_HAND + 15, 2, __VA_ARGS__},
    // {R_HAND + 15, 2, __VA_ARGS__}

#define SET_NON_CORNE_LIGHTS(...) \
    SET_ROW_0(__VA_ARGS__), \
    {L_HAND + 6, 1, __VA_ARGS__}, \
    {R_HAND + 6, 1, __VA_ARGS__}, \
    {L_HAND + 15, 1, __VA_ARGS__}, \
    {R_HAND + 15, 1, __VA_ARGS__}

#define SET_LAYER_ID(...)     \
    SET_UNDERGLOW(__VA_ARGS__), \
    SET_BOTTOM_MODIFIERS(__VA_ARGS__), \
    SET_THUMB_CLUSTER(__VA_ARGS__), \
    SET_LAYER_SWITCHERS(HSV_LAYER_SWITCH)
    //SET_OUTER_COL(__VA_ARGS__),


#define SET_OSM(hand, row) \
    {hand + led_index[row][1], 1, HSV_MODS}, \
    {hand + led_index[row][2], 1, HSV_MODS}, \
    {hand + led_index[row][3], 1, HSV_MODS}, \
    {hand + led_index[row][4], 1, HSV_MODS}


#define SET_NAVIGATION() \
    {L_HAND + led_index[1][5], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][1], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][2], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[2][3], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[2][4], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[2][5], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[3][1], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[3][2], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[3][3], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[3][4], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[3][5], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[1][0], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][1], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][2], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[1][3], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][4], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[1][5], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][0], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[2][1], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][2], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][3], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][4], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][5], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[3][0], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[3][1], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[3][2], 1, HSV_BLACK}, \
    {R_HAND + led_index[3][3], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[3][4], 1, HSV_LAYER_SWITCH}, \
    {R_HAND + led_index[3][5], 1, HSV_BLACK}

#define SET_BRACKETS() \
    {L_HAND + led_index[1][3], 3, HSV_ALPHAS_ACCENT}, \
    {L_HAND + led_index[3][4], 3, HSV_ALPHAS_ACCENT}

const int led_index[5][6] = {
    {10, 11, 20, 21, 30, 31},
    { 9, 12, 19, 22, 29, 32},
    { 8, 13, 18, 23, 28, 33 },
    { 7, 14, 17, 24, 27, 34},
    { 6, 15, 16, 25, 26, 0},
};

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
