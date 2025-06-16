#ifndef COLOURGENERATOR_H
#define  COLOURGENERATOR_H

#include "Colour.h"
#include <vector>

class ColourGenerator
{
public:
    std::vector<std::vector<Colour>> generateColours(std::vector<std::vector<float>> heights, float amplitude);
    Colour calculateColour(float height, float amplitude);
    ColourGenerator(std::vector<Colour> biomeColours, float spread);
    ~ColourGenerator();
private:
    float spread;
    float halfSpread;
    float part;
    std::vector<Colour> biomeColours; 
};

#endif
