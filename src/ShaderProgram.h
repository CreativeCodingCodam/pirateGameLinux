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
