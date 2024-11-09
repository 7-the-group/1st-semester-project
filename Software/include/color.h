#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct ColorRGB
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct ColorHSV
{
    unsigned int h; // 0 - 360
    float s; // 0 - 1
    float v; // 0 - 1
};

struct ColorRGB convert_HSV_to_RGB(struct ColorHSV hsv);
struct ColorHSV convert_RGB_to_HSV(struct ColorRGB rgb);

#endif