#include "Noise.h"
#include "PerlinNoise.h"
#include <vector>


std::vector<std::vector<float>> Noise::generateNoiseMap(int mapWidth, int mapHeight, float scale)
{
        std::vector<std::vector<float>> noiseMap(mapWidth, vector<float>(mapHeight, 0));
        PerlinNoise noise(1, 5, 0.35f);

        if (scale <= 0)
            scale = 0.0001f;
    
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                float sampleX = x / scale;
                float sampleY = y / scale;

                float perlinValue = noise.getPerlinNoise(sampleX, sampleY);
                noiseMap[x][y] = perlinValue;
            }
        }
        return (noiseMap);

}
