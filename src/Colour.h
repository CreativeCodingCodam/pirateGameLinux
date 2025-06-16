#ifndef COLOUR_H
#define COLOUR_H

class Colour {
public:
    int getRed();
    int getGreen();
    int getBlue();
    int getAlpha();
//  implement interpolateColours();
    Colour(int r, int g, int b, float a);
    ~Colour();
private:
    int r;
    int g;
    int b;
    float a;
};

#endif // !COLOUR_H
