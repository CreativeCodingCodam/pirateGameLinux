#ifndef ENDLESSTERRAIN_H
#define ENDLESSTERRAIN_H

#include "of3dPrimitives.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include "ofVec3f.h"
#include <unordered_map>

struct KeyFuncs
{
    size_t operator()(const ofVec2f& k)const
    {
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y);
    }

    bool operator()(const ofVec2f& a, const ofVec2f& b)const
    {
            return a.x == b.x && a.y == b.y;
    }
};

class TerrainChunk
{
public:

    TerrainChunk()
    {
    }

    TerrainChunk(ofVec2f coordinate, int size)
    {
        this->size = size;
        position = coordinate * size;
        ofVec3f positionV3 = ofVec3f(position.x, position.y ,0);
        plane.setPosition(positionV3);
        plane.setScale(ofVec3f(1,1,1) * size);
    }

    void update(ofVec3f viewerPosition, int maxViewDistance)
    {
        ofVec2f boxSize = ofVec2f(size, size);
        ofVec2f halfSize = boxSize * 0.5f;

        float left = position.x - halfSize.x;
        float right = position.x + halfSize.x;
        float top = position.y - halfSize.y;
        float bottom = position.y + halfSize.y;
        
        float dx = std::max({left - viewerPosition.x, viewerPosition.x - right});
        float dy = std::max({top - viewerPosition.y, viewerPosition.y - bottom});
        
        ofVec2f distance(dx, dy);
        float viewerDistanceFromEdge = distance.length();
        std::cout << "distance from edge: " << viewerDistanceFromEdge << "\n";
        plane.draw();
    }

    void setVisible()
    {
       plane.drawWireframe(); 
    }


        
private:
    ofVec2f position;
    int size;
    ofPlanePrimitive plane;
};

class EndlessTerrain {
public:
    const float maxViewDistance = 30;
    ofVec2f viewerPosition;
    std::unordered_map<ofVec2f, TerrainChunk, KeyFuncs, KeyFuncs> terrainChunkDictionary;

    void Start(int chunkSize)
    {
        this->chunkSize = chunkSize;
        chunksVisibleInViewDistance = std::round(maxViewDistance / chunkSize);
    }

    void update(const ofVec3f &viewer)
    {
        viewerPosition = ofVec2f(viewer.x, viewer.z);
        // std::cout << "viewer x: " << viewerPosition.x << "viewer y: " << viewer.y << std::endl;
        UpdateVisibleChunks();
    }
    
    void UpdateVisibleChunks()
    {
        int currentChunkCoordinateX = std::round(viewerPosition.x / chunkSize);
        int currentChunkCoordinateY = std::round(viewerPosition.y / chunkSize);
        for (int yOffset = -chunksVisibleInViewDistance; yOffset <= chunksVisibleInViewDistance; yOffset++) {
            for (int xOffset = -chunksVisibleInViewDistance; xOffset <= chunksVisibleInViewDistance; xOffset++) {
                ofVec2f viewedChunkCoordinate = ofVec2f(currentChunkCoordinateX + xOffset, currentChunkCoordinateY + yOffset);
                std::cout << "viewerPosition.x: " << viewerPosition.x << "\nviewerPosition.y: " << viewerPosition.y << 
                    "\nchunkcoord.x "<< viewedChunkCoordinate.x << "\nchunkcoord.y " << viewedChunkCoordinate.y 
                    << "\nxOffset" << xOffset << "\nyOffset: " << yOffset << "\n";
                // std::cout << "x: " << viewedChunkCoordinate.x << " y: " << viewedChunkCoordinate.y << std::endl;
                if (terrainChunkDictionary.contains(viewedChunkCoordinate))
                {
                    terrainChunkDictionary[viewedChunkCoordinate].update(viewerPosition, maxViewDistance);
                }
                else
                {
                    terrainChunkDictionary.insert({ viewedChunkCoordinate, TerrainChunk(viewedChunkCoordinate, chunkSize) });
                }
            }
        }
    }

private:
    int chunkSize;
    int chunksVisibleInViewDistance;

};

#endif // !ENDLESSTERRAIN_H
