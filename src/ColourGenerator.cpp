#include "ColourGenerator.h"
#include <algorithm>
#include <cmath>
#include <vector>

typedef struct RgbColor
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RgbColor;

typedef struct HsvColor
{
    unsigned char h;
    unsigned char s;
    unsigned char v;
} HsvColor;

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

std::vector<std::vector<Colour>> ColourGenerator::generateColours(std::vector<std::vector<float>> heights, float amplitude)
{
    std::vector<std::vector<Colour>> colours;
    for (int z = 0; z < heights.size(); z++) 
    {
        for (int x = 0; x < heights[z].size() ; x++) 
        {
            colours[z][x] = calculateColour(heights[z][x], amplitude);
        }
    }
    return (colours);
}

Colour ColourGenerator::calculateColour(float height, float amplitude)
{
    float value = (height * amplitude) / (amplitude * 2);
    value = std::clamp((value - halfSpread) * (1.0f / spread), 0.0f, 0.9999f);
    int firstBiome = std::floor(value / part);
    float blend = (value - (firstBiome * part)) / part;
    return (Colour::interpolateColours(biomeColours[firstBiome], biomeColours[firstBiome + 1], blend));
}

ColourGenerator::ColourGenerator(std::vector<Colour> biomeColours, float spread)
:  spread(spread), halfSpread(spread / 2), part(1.0f / (biomeColours.size() - 1)), biomeColours(biomeColours)
{
}

ColourGenerator::~ColourGenerator()
{
}
