#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include "ofMain.h"
#include <cstdlib>

class PerlinNoise {
public:
    int getSeed();
    float getAmplitude();
    float getPerlinNoise(int x, int y);
    float getSmoothNoise(int x, int y);
    float getNoise(int x, int y);
    float getInterpolatedNoise(float x, float y);
    float interpolate(float a, float b, float blend);

    PerlinNoise(int seed, int octaves, float amplitude, float roughness);
    PerlinNoise(int octaves, float amplitude, float roughness);
private:
    int seed;
    float roughness;
    int octaves;
    float amplitude;
};


#endif 
