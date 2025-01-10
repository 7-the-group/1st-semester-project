#include <color.h>
#include <math.h>
#include <RGBConverter.h>

ColorRGB convert_HSV_to_RGB(ColorHSV hsv)
{
    uint8_t rgb_out[3];
    hsvToRgb(hsv.h / 360.0, hsv.s, hsv.v, rgb_out);

    ColorRGB rgb;
    rgb.r = rgb_out[0];
    rgb.g = rgb_out[1];
    rgb.b = rgb_out[2];

    return rgb;
}

ColorHSV convert_RGB_to_HSV(ColorRGB rgb)
{
    double hsv_out[3];
    rgbToHsv(rgb.r, rgb.g, rgb.b, hsv_out);

    ColorHSV hsv;
    hsv.h = hsv_out[0] * 360.0;
    hsv.s = hsv_out[1];
    hsv.v = hsv_out[2];

    return hsv;
}