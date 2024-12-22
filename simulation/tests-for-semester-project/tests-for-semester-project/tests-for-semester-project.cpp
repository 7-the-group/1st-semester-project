#include <iostream>

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

ColorRGB convert_HSV_to_RGB(ColorHSV hsv) // ChatGPT wrote it
{
    float hh, p, q, t, ff;
    long i;
    ColorRGB rgb;

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

ColorHSV convert_RGB_to_HSV(ColorRGB rgb) // ChatGPT wrote it
{
    float maxc, minc, rc, gc, bc, h_tmp;

    float r = rgb.r / 255.0f;
    float g = rgb.g / 255.0f;
    float b = rgb.b / 255.0f;
    
    float hue, saturation, value;

    maxc = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
    minc = (r < g) ? ((r < b) ? r : b) : ((g < b) ? g : b);
    value = maxc;

    // If the min and max values are the same, it's a shade of gray (no hue, no saturation)
    if (minc == maxc) {
        hue = 0.0f;
        saturation = 0.0f;

        ColorHSV hsv = { hue, saturation, value };
        return hsv;
    }

    // Saturation calculation
    saturation = (maxc - minc) / maxc;

    // Calculate the RGB components normalized by the range (max - min)
    rc = (maxc - r) / (maxc - minc);
    gc = (maxc - g) / (maxc - minc);
    bc = (maxc - b) / (maxc - minc);

    // Hue calculation based on which RGB component is the maximum
    if (r == maxc) {
        h_tmp = bc - gc;
    }
    else if (g == maxc) {
        h_tmp = 2.0 + rc - bc;
    }
    else {
        h_tmp = 4.0 + gc - rc;
    }

    // Normalize hue to be in the range [0, 360]
    hue = h_tmp * 60;
    if (hue < 0.0f)
    {
        hue += 360.0f;
    }

    ColorHSV hsv = { hue, saturation, value };
    return hsv;
}
    
int main()
{
    ColorRGB rgb = { 200, 165, 233 };
    ColorHSV hsv = { 300, 1.0f, 1.0f };
    
    ColorHSV convertedToHSV = convert_RGB_to_HSV(rgb);
    ColorRGB convertedToRGB = convert_HSV_to_RGB(hsv);

    ColorRGB convertedBackToRGB = convert_HSV_to_RGB(convertedToHSV);
    ColorHSV convertedBackToHSV = convert_RGB_to_HSV(convertedToRGB);

    return 0;
}
