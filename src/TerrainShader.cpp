#include "TerrainShader.h"
#include "ShaderProgram.h"

TerrainShader::TerrainShader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
: ShaderProgram { vertexFile, fragmentFile }
{
}

TerrainShader::TerrainShader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile)
: ShaderProgram(vertexFile, fragmentFile, geometryFile)
{
}
