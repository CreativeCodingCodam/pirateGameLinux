#include "ShaderProgram.h"
#include "ofShader.h"
#include <filesystem>

void ShaderProgram::begin(void)
{
    shader.begin();
}
 
void ShaderProgram::end(void)
{
    shader.end();
}

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
{
    shader.load(vertexFile, fragmentFile);
}

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile)
{
    shader.load(vertexFile, fragmentFile, geometryFile);
}
