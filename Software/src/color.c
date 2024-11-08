#include <color.h>

struct ColorRGB convert_HSV_to_RGB(struct ColorHSV hsv) // ChatGPT wrote it
{
    float hh, p, q, t, ff;
    long i;
    struct ColorRGB rgb;

    if (hsv.s <= 0.0) { // If saturation is 0, the color is a shade of gray
        rgb.r = rgb.g = rgb.b = (int)(hsv.v * 255.0);
        return rgb;
    }

    hh = hsv.h;
    if (hh >= 360.0)
        hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = hsv.v * (1.0 - hsv.s);
    q = hsv.v * (1.0 - (hsv.s * ff));
    t = hsv.v * (1.0 - (hsv.s * (1.0 - ff)));

    switch (i) {
    case 0:
        rgb.r = (int)(hsv.v * 255.0);
        rgb.g = (int)(t * 255.0);
        rgb.b = (int)(p * 255.0);
        break;
    case 1:
        rgb.r = (int)(q * 255.0);
        rgb.g = (int)(hsv.v * 255.0);
        rgb.b = (int)(p * 255.0);
        break;
    case 2:
        rgb.r = (int)(p * 255.0);
        rgb.g = (int)(hsv.v * 255.0);
        rgb.b = (int)(t * 255.0);
        break;

    case 3:
        rgb.r = (int)(p * 255.0);
        rgb.g = (int)(q * 255.0);
        rgb.b = (int)(hsv.v * 255.0);
        break;
    case 4:
        rgb.r = (int)(t * 255.0);
        rgb.g = (int)(p * 255.0);
        rgb.b = (int)(hsv.v * 255.0);
        break;
    case 5:
    default:
        rgb.r = (int)(hsv.v * 255.0);
        rgb.g = (int)(p * 255.0);
        rgb.b = (int)(q * 255.0);
        break;
    }
    return rgb;
}

struct ColorHSV convert_RGB_to_HSV(struct ColorRGB rgb) // ChatGPT wrote it
{
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    float max = (r > g ? (r > b ? r : b) : (g > b ? g : b));
    float min = (r < g ? (r < b ? r : b) : (g < b ? g : b));
    float delta = max - min;

    struct ColorHSV hsv;
    hsv.v = max;

    if (delta < 0.00001) { // if max == min, then it's a shade of gray
        hsv.s = 0;
        hsv.h = 0; // Undefined, maybe nan?
        return hsv;
    }

    if (max > 0.0) {
        hsv.s = delta / max; // Saturation
    } else {
        hsv.s = 0.0;
        hsv.h = 0.0; // Undefined
        return hsv;
    }

    if (r >= max)
        hsv.h = (g - b) / delta;
    else if (g >= max)
        hsv.h = 2.0 + (b - r) / delta;
    else
        hsv.h = 4.0 + (r - g) / delta;

    hsv.h *= 60.0; // Convert to degrees

    if (hsv.h < 0.0)
        hsv.h += 360.0;

    return hsv;
}