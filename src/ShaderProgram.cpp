#include "ShaderProgram.h"
#include "ofShader.h"
#include <filesystem>

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
{
    shader.load(vertexFile, fragmentFile);
}

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile)
{
    shader.load(vertexFile, fragmentFile, geometryFile);
}
