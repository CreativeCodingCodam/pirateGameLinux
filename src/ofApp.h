#pragma once

#include "Player.h"
#include "of3dPrimitives.h"
#include "ofEasyCam.h"
#include "ofLight.h"
#include "ofMain.h"
#include "ofMaterial.h"

enum GameState {
  none,
  start,
  game,
  ending,
};

class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  int gameState;
  Player player;

  ofPlanePrimitive plane;
  ofEasyCam cam;
  ofMaterial roadMaterial;
  ofLight light;
};
