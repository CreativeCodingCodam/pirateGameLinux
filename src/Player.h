#include "ofMain.h"

class Player {
public:
  ofPoint pos;
  float width, height, speed;
  bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
  void setup();
  void update();
  void draw();
  void calculate_movement();
};
