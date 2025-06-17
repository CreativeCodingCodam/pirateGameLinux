#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "ofMatrix4x4.h"
#include "ofShader.h"
#include "ofVec2f.h"
#include "ofVec3f.h"
#include <filesystem>
#include <fstream>

class ShaderProgram
{
public:
    void begin();
    void end();
    void setUniformMatrix4f(const std::string &name, glm::mat4 m);
    void setUniform3f(const std::string &name, glm::vec3 v);
    void setUniform2f(const std::string &name, glm::vec2 v);
    ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);
    ShaderProgram(std::filesystem::path vertexFile, std::filesystem::path fragmentFile, std::filesystem::path geometryFile);
protected:
    ofMatrix4x4 projectionMatrix;
    ofVec3f lightDirection;
    ofVec3f lightColour;
    ofVec2f lightBias;
    ofShader shader;
};

#endif // !SHADERPROGRAM_H
