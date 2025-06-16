#ifndef COLOUR_H
#define COLOUR_H

#include "ofMain.h"
#include <cstdlib>

typedef struct RgbColor
{
    int r;
    int g;
    int b;
} RgbColor;

typedef struct HsvColor
{
    int h;
    int s;
    int v;
} HsvColor;

class Colour {
public:
    int getRed();
    int getGreen();
    int getBlue();
    int getAlpha();
    static Colour interpolateColours(Colour color1, Colour color2, float blend);
    Colour(int r, int g, int b, float a);
    ~Colour();
private:
    int r;
    int g;
    int b;
    float a;
};

#endif // !COLOUR_H
