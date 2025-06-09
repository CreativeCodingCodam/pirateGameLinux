#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { gameState = start; }

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
    player.draw();
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
