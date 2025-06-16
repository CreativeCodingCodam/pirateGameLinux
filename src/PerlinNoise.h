#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include "ofMain.h"

class PerlinNoise {
public:
    int getSeed();
    float getAmplitude();
    float getPerlinNoise();
    float getSmoothNoise();
    float getNoise();
    float getInterpolatedNoise();
    float interpolate();

    PerlinNoise(int seed, int octaves, float amplitude, float roughness);
    PerlinNoise(int octaves, float amplitude, float roughness);
private:
    int seed;
    float roughness;
    int octaves;
    float amplitude;
};


#endif 
