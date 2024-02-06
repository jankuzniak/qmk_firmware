#pragma once

// colour palette
// max brigtness is 120 (set in RGBLIGHT_LIMIT_VAL)

#define BASE_V 120

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
#define HSV_ALPHAS          DHUSAR_GREY
#define HSV_ALPHAS_ACCENT   LILAS
#define HSV_MODS            SUGAR_GRAPE
#define HSV_LAYER_SWITCH    BUDDHAS_LOVE_HANDLES
#define HSV_NUMBERS         BIG_YELLOW_TAXI
#define HSV_NAVIGATION      DODGER_BLUE
#define HSV_FUNCTION        ALIEN_PARASITE
#define HSV_SPECIAL         BRIGHT_ORANGE

#define LEDS_COUNT 27
#define L_HAND 0
#define R_HAND L_HAND + LEDS_COUNT

// Light combinations
#define SET_ALL(...) \
    {0, 2 * LEDS_COUNT, __VA_ARGS__}

#define SET_HAND(hand, ...) \
    {hand, LEDS_COUNT, __VA_ARGS__}

#define SET_UNDERGLOW(...) \
    {L_HAND + 0, 6, __VA_ARGS__}, \
    {R_HAND + 0, 6, __VA_ARGS__}

#define SET_LAYER_SWITCHERS(...) \
    {L_HAND + led_index[3][5], 1, __VA_ARGS__}, \
    {R_HAND + led_index[3][5], 1, __VA_ARGS__}

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

#define SET_LAYER_ID(...)     \
    SET_UNDERGLOW(__VA_ARGS__), \
    SET_LAYER_SWITCHERS(HSV_LAYER_SWITCH)

#define SET_NUMPAD(...) \
    {R_HAND + 10, 3, __VA_ARGS__}, \
    {R_HAND + 15, 6, __VA_ARGS__}

#define SET_OSM(hand, row) \
    {hand + led_index[row][1], 1, HSV_MODS}, \
    {hand + led_index[row][2], 1, HSV_MODS}, \
    {hand + led_index[row][3], 1, HSV_MODS}, \
    {hand + led_index[row][4], 1, HSV_MODS}

#define SET_NAVIGATION() \
    {L_HAND + led_index[0][5], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[1][1], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[1][2], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[1][3], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[1][4], 1, HSV_NAVIGATION}, \
    {L_HAND + led_index[1][5], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][1], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][2], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][3], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][4], 1, HSV_FUNCTION}, \
    {L_HAND + led_index[2][5], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[0][0], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[0][1], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[0][2], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[0][3], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[0][4], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[0][5], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][0], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[1][1], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][2], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][3], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][4], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[1][5], 1, HSV_NAVIGATION}, \
    {R_HAND + led_index[2][0], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[2][1], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[2][2], 1, HSV_BLACK}, \
    {R_HAND + led_index[2][3], 1, HSV_FUNCTION}, \
    {R_HAND + led_index[2][4], 1, HSV_LAYER_SWITCH}, \
    {R_HAND + led_index[2][5], 1, HSV_BLACK}

#define SET_BRACKETS() \
    {L_HAND + led_index[2][3], 3, HSV_ALPHAS_ACCENT}, \
    {L_HAND + led_index[0][4], 3, HSV_ALPHAS_ACCENT}

const int led_index[4][6] = {
  {24, 23, 18, 17, 10, 9},
  {25, 22, 19, 16, 11, 8},
  {26, 21, 20, 15, 12, 7},
  { 0,  0,  0, 14, 13, 6},
};
/*
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5         6  7  8  9  10 11
  //                                              ROWS
  // 24 23 18 17 10 09        09 10 17 18 23 24   1
  //    02    01    00        02    01    00
  // 25 22 19 16 11 08        08 11 16 19 22 25   2
  //    03    04    05        05    04    03
  // 26 21 20 15 12 07        07 12 15 20 21 26   3
  //          14 13 06        06 13 14            4
*/
