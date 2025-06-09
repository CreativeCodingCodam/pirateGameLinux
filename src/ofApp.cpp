#include "ofApp.h"
#include "fwd.hpp"
#include "ofAppRunner.h"
#include "ofLight.h"

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

  // Set our camera up in a nice location to view our awesome car
  cam.setPosition(-965, 586, -1084);
  glm::vec3 point;
  cam.lookAt(point, {0.f, 1.f, 0.f});
  cam.setFarClip(10000);

  gameState = start;
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
    ofBackgroundGradient(ofColor(10), ofColor(50));

    ofEnableDepthTest();
    cam.begin();
    roadMaterial.begin();
    plane.draw();
    roadMaterial.end();
    player.draw();
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
