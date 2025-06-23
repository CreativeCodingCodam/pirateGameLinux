#ifndef NOISE_H
#define NOISE_H

#include "PerlinNoise.h"
#include <vector>

class Noise 
{
public:
    std::vector<std::vector<float>> generateNoiseMap(int mapWidth, int mapHeight, float scale);
}; 

#endif // !NOISE_H
