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

void ShaderProgram::setUniformMatrix4f(const std::string &name, glm::mat4 m)
{
    shader.setUniformMatrix4f(name, m, 1);
}

void ShaderProgram::setUniform3f(const std::string &name, glm::vec3 v)
{
    shader.setUniform3f(name, v);
}

void ShaderProgram::setUniform2f(const std::string &name, glm::vec2 v)
{
    shader.setUniform2f(name, v);
}

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
{
    shader.load(vertexFile, fragmentFile);
}

ShaderProgram::ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile)
{
    shader.load(vertexFile, fragmentFile, geometryFile);
}
