#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct ColorRGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct ColorHSV
{
    uint16_t h; // 0 - 360
    float s; // 0 - 1
    float v; // 0 - 1
};

struct ColorRGB convert_HSV_to_RGB(struct ColorHSV hsv);
struct ColorHSV convert_RGB_to_HSV(struct ColorRGB rgb);

#endif