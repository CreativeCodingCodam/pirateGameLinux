#include "ColourGenerator.h"
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<ofFloatColor> ColourGenerator::generateColours(std::vector<ofVec3f> vertices, float amplitude)
{
    std::vector<ofFloatColor> colours;
    int gridSize = vertices.size();
    for (int x = 0; x < gridSize; x++) 
   {
        for (int y = 0; y < gridSize; y++) 
        {
            colours.push_back(calculateColour(vertices[x + y].z, amplitude));
        }
    }
    return (colours);
}

ofFloatColor ColourGenerator::calculateColour(float height, float amplitude)
{
    float value = (height * amplitude) / (amplitude * 2);
    value = std::clamp((value - halfSpread) * (1.0f / spread), 0.0f, 0.9999f);
    int firstBiome = std::floor(value / part);
    float blend = (value - (firstBiome * part)) / part;
    return (biomeColours[firstBiome].lerp(biomeColours[firstBiome + 1], blend));
}

ColourGenerator::ColourGenerator(std::vector<ofFloatColor> biomeColours, float spread)
:  spread(spread), halfSpread(spread / 2), part(1.0f / (biomeColours.size() - 1)), biomeColours(biomeColours)
{
}

ColourGenerator::~ColourGenerator()
{
}
