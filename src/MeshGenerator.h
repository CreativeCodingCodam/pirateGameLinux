#ifndef MESHGENERATOR_H
#define MESHGENERATOR_H

#include "ofMain.h"
#include "PerlinNoise.h"

class MeshGenerator
{
public:
    MeshGenerator(){};
    ofMesh generateTerrainMesh(int height, int width, PerlinNoise noise)
    {
        generateVertices(height, width, noise);
        generateIndices(height, width);
        return (mesh);
    }

    void generateVertices(int height, int width, PerlinNoise noise)
    {
        int scale = 200;
        float topLeftX = ((width - 1) / -2.0f) * scale;
        float topLeftY = ((height - 1) / 2.0) * scale;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                mesh.addVertex(ofPoint(topLeftX + x , topLeftY - y , ofMap(noise.getPerlinNoise(x,y), 0, 1, -10000, 10000)));
                mesh.addColor(ofFloatColor(ofNoise(x, y), ofNoise(y, x), ofNoise(x, x)));
            }
        }
    }

    void generateIndices(int height, int width)
    {
        for (int y = 0; y < height - 1; y++) {
            for (int x = 0; x < width - 1; x++) {
                mesh.addIndex(x + y * width);       // 0
                mesh.addIndex((x + 1) + y * width); // 1
                mesh.addIndex(x + (y + 1) * width); // 10

                mesh.addIndex((x + 1) + y * width);       // 1
                mesh.addIndex((x + 1) + (y + 1) * width); // 11
                mesh.addIndex(x + (y + 1) * width);       // 10
            }
        }
    }

private:
    ofMesh mesh;

};

#endif // !MESHGENERATOR_H
