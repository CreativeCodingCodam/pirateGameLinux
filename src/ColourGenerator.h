#ifndef COLOURGENERATOR_H
#define  COLOURGENERATOR_H

#include "ofMain.h"
#include <vector>

class ColourGenerator
{
public:
    std::vector<ofFloatColor> generateColours(std::vector<ofVec3f> heights, float amplitude);
    ofFloatColor calculateColour(float height, float amplitude);
    ColourGenerator(std::vector<ofFloatColor> biomeColours, float spread);
    ColourGenerator();
    ~ColourGenerator();
private:
    float spread;
    float halfSpread;
    float part;
    std::vector<ofFloatColor> biomeColours; 
};

#endif
