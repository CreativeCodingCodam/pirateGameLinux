#include "ofApp.h"
#include "ColourGenerator.h"
#include "PerlinNoise.h"
#include "TerrainGenerator.h"
#include "BaseTerrainGenerator.h"
#include "TerrainRenderer.h"
#include "fwd.hpp"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofLight.h"
#include "ofMath.h"
#include "ofPoint.h"

//--------------------------------------------------------------
void ofApp::setup() {
  light.setup();
  light.setPosition(-100, 200, 100);
  light.setAmbientColor(ofFloatColor(0.4, 1.0));

  plane.set(10000, 10000);
  plane.rotateDeg(270, 1, 0, 0);
  plane.move(0, -49, 0);

  ofFloatColor roadColor(100, 0.7, 200);
  roadMaterial.setAmbientColor(roadColor);
  roadMaterial.setDiffuseColor(roadColor);
  roadMaterial.setShininess(0.01);
  ofBackground(99, 187, 204);

  PerlinNoise noise = PerlinNoise(1, 5, 500, 0.10f);

  int width = 100, height = 100;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      mesh.addVertex(ofPoint(x * 5, y * 5, ofMap(noise.getPerlinNoise(x, y), 100, 600, -150, 350, false)));
      mesh.addColor(ofFloatColor(ofNoise(x,y), ofNoise(y,x), ofNoise(x,x)));
    }
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      waterMesh.addVertex(ofPoint(x * 5, y * 5, 0));
      waterMesh.addColor(ofFloatColor(0,0,0));
    }
  }
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
  for (int y = 0; y < height - 1; y++) {
    for (int x = 0; x < width - 1; x++) {
      waterMesh.addIndex(x + y * width);       // 0
      waterMesh.addIndex((x + 1) + y * width); // 1
      waterMesh.addIndex(x + (y + 1) * width); // 10

      waterMesh.addIndex((x + 1) + y * width);       // 1
      waterMesh.addIndex((x + 1) + (y + 1) * width); // 11
      waterMesh.addIndex(x + (y + 1) * width);       // 10
    }
  }
  // Set our camera up in a nice location to view our awesome car
  cam.setPosition(-150, 150, -800);
  glm::vec3 point;
  cam.lookAt(point, {0.0f,1.0f,0.0f});
  cam.setFarClip(10000);

  gameState = start;


  // for (int x = 0; x < 10; x++) {
  //   for (int y = 0; y < 10; y++) {
  //       std::cout << "x: " << x << "y: " << y << std::endl;
  //       // std::cout << "interpolatedNoise " << noise.getInterpolatedNoise(x, y) << std::endl;
  //       // std::cout << "Noise " << noise.getNoise(x, y) << std::endl;
  //       std::cout << "PerlinNoise " << noise.getPerlinNoise(x, y) << std::endl;
  //       // std::cout << "SmoothNoise " << noise.getSmoothNoise(x, y) << std::endl;
  //   }
  // }
  std::vector<ofFloatColor> colors = { 
    { 201, 178, 99, 1 },
	{ 135, 184, 82, 1 }, 
    { 80, 171, 93, 1 }, 
    { 120, 120, 120, 1 },
	{ 200, 200, 210, 1 } 
  };
  // ColourGenerator colourGen = ColourGenerator(colors, 0.45f);
  // terrainGenerator = BaseTerrainGenerator(noise, colourGen);
  // terrain = terrainGenerator.generateTerrain(10);
}

//--------------------------------------------------------------
void ofApp::update() {
  if (gameState == start) {

  } else if (gameState == game) {
    player.update();

  } else if (gameState == ending) {
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  if (gameState == start) {

  } else if (gameState == game) {
    ofBackgroundGradient(ofColor(50), ofColor(50));

    ofEnableDepthTest();
    cam.begin();
    ofPushMatrix();
    // terrainGenerator.render(terrain, cam, light);
    ofRotateXDeg(90);
    ofTranslate(ofPoint(-250, -250));
    waterMesh.drawWireframe();
    mesh.draw();
    // mesh.drawWireframe();
    ofPopMatrix();
    // roadMaterial.begin();
    // plane.draw();
    // roadMaterial.end();
    // player.draw();
    cam.end();

    ofDisableDepthTest();
  } else if (gameState == ending) {
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (gameState == start) {
    gameState = game;
  } else if (gameState == game) {
    if (key == OF_KEY_LEFT) {
      player.is_left_pressed = true;
    }

    if (key == OF_KEY_RIGHT) {
      player.is_right_pressed = true;
    }

    if (key == OF_KEY_UP) {
      player.is_up_pressed = true;
    }

    if (key == OF_KEY_DOWN) {
      player.is_down_pressed = true;
    }
    if (key == OF_KEY_ESC) {
      ofExit();
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  if (gameState == start) {
    gameState = game;
  } else if (gameState == game) {
    if (key == OF_KEY_LEFT) {
      player.is_left_pressed = false;
    }

    if (key == OF_KEY_RIGHT) {
      player.is_right_pressed = false;
    }

    if (key == OF_KEY_UP) {
      player.is_up_pressed = false;
    }

    if (key == OF_KEY_DOWN) {
      player.is_down_pressed = false;
    }
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
