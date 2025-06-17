#include "TerrainRenderer.h"
#include "ofConstants.h"


TerrainRenderer::TerrainRenderer(TerrainShader shader, bool usesIndices)
: shader(shader), hasIndices(usesIndices)
{
}

void TerrainRenderer::render(Terrain terrain, ofCamera camera, ofLight light)
{
    prepare(terrain, camera, light);
    if (hasIndices)
        terrain.getVbo().drawElements(GL_TRIANGLES, terrain.getVertexCount());
    else
        terrain.getVbo().draw(GL_TRIANGLES, 0, terrain.getVertexCount());
    finish(terrain);
}

void TerrainRenderer::prepare(Terrain terrain, ofCamera camera, ofLight light)
{
    terrain.getVbo().bind();
    shader.begin();
    shader.setUniform3f("lightDirection", light.getLookAtDir());
    // TODO figure how to create vector from color float
    shader.setUniform3f("lightColour", light.getDiffuseColor());
    shader.setUniform2f("lightBias", glm::vec2(0.5, 0.5));
    shader.setUniformMatrix4f("projectionViewMatrix", camera.getModelViewProjectionMatrix());
}

void TerrainRenderer::finish(Terrain terrain)
{
    terrain.getVbo().unbind();
    shader.end();
}
