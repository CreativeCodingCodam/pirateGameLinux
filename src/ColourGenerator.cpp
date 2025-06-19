#include "ColourGenerator.h"
#include <algorithm>
#include <cmath>
#include <vector>

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
