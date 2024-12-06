#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <stdint.h>

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ColorRGB;

typedef struct
{
    uint16_t h; // 0 - 360
    float s; // 0 - 1
    float v; // 0 - 1
} ColorHSV;

ColorRGB convert_HSV_to_RGB(ColorHSV hsv);
ColorHSV convert_RGB_to_HSV(ColorRGB rgb);

#endif