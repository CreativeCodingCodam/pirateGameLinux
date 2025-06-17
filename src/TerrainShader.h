#ifndef TERRAINSHADER_H
#define TERRAINSHADER_H

#include "ShaderProgram.h"
#include <filesystem>
#include <fstream>

class TerrainShader : public ShaderProgram
{
public:
    TerrainShader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);
    TerrainShader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile);
};
#endif // !TerrainShader

