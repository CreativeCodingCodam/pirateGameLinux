#include "Colour.h"

int Colour::getRed()
{
    return (r);
}

int Colour::getGreen()
{
    return (g);
}

int Colour::getBlue()
{
    return (b);
}

int Colour::getAlpha()
{
    return (a);
}

RgbColor HsvToRgb(HsvColor hsv)
{
    RgbColor rgb;
    unsigned char region, remainder, p, q, t;
    
    if (hsv.s == 0)
    {
        rgb.r = hsv.v;
        rgb.g = hsv.v;
        rgb.b = hsv.v;
        return (rgb);
    }
    
    region = hsv.h / 43;
    remainder = (hsv.h - (region * 43)) * 6; 
    
    p = (hsv.v * (255 - hsv.s)) >> 8;
    q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
    t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
    
    switch (region)
    {
        case 0:
            rgb.r = hsv.v; rgb.g = t; rgb.b = p;
            break;
        case 1:
            rgb.r = q; rgb.g = hsv.v; rgb.b = p;
            break;
        case 2:
            rgb.r = p; rgb.g = hsv.v; rgb.b = t;
            break;
        case 3:
            rgb.r = p; rgb.g = q; rgb.b = hsv.v;
            break;
        case 4:
            rgb.r = t; rgb.g = p; rgb.b = hsv.v;
            break;
        default:
            rgb.r = hsv.v; rgb.g = p; rgb.b = q;
            break;
    }
    
    return (rgb);
}

HsvColor RgbToHsv(RgbColor rgb)
{
    HsvColor hsv;
    unsigned char rgbMin, rgbMax;

    rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
    rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);
    
    hsv.v = rgbMax;
    if (hsv.v == 0)
    {
        hsv.h = 0;
        hsv.s = 0;
        return (hsv);
    }

    hsv.s = 255 * long(rgbMax - rgbMin) / hsv.v;
    if (hsv.s == 0)
    {
        hsv.h = 0;
        return (hsv);
    }

    if (rgbMax == rgb.r)
        hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
    else if (rgbMax == rgb.g)
        hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
    else
        hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);

    return (hsv);
}

Colour Colour::interpolateColours(Colour color1, Colour color2, float blend)
{
    double theta = blend * M_PI;
    float f = (float) ((1.0f - cos(theta)) * 0.5f);

    int r1 = color1.getRed();
    int r2 = color2.getRed();
    int g1 = color1.getGreen();
    int g2 = color2.getGreen();
    int b1 = color1.getBlue();
    int b2 = color2.getBlue();
    int a1 = color1.getAlpha();
    int a2 = color2.getAlpha();

    RgbColor rgb1 = {r1, g1, b1};
    RgbColor rgb2 = {r2, g2, b2};
    HsvColor hsv1 = RgbToHsv(rgb1);
    HsvColor hsv2 = RgbToHsv(rgb2);
    HsvColor interpolatedHsv = {
        (int)((hsv2.h - hsv1.h) * (1.0 - f) + hsv1.h),
        (int)((hsv2.s - hsv1.s) * (1.0 - f) + hsv1.s),
        (int)((hsv2.v - hsv1.v) * (1.0 - f) + hsv1.v)};
    RgbColor interpolatedRgb = HsvToRgb(interpolatedHsv);
    Colour interpolatedColour(
            interpolatedRgb.r, 
            interpolatedRgb.g,
            interpolatedRgb.b,
            ((a2-a1) * (1 - f) + a1));
    return (interpolatedColour);
}

Colour::Colour(int r, int g, int b, float a)
: r(r), g(g), b(b), a(a)
{
}

Colour::~Colour()
{
}
