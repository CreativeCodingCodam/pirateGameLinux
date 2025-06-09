#include "Player.h"
#include "ofGraphics.h"
#include "ofPoint.h"
void Player::setup() { pos = ofPoint(width / 2, height / 2); }

void Player::update() {
  if (is_right_pressed == true)
    pos.x += 1;
  if (is_left_pressed == true)
    pos.x -= 1;
  if (is_down_pressed == true)
    pos.y += 1;
  if (is_up_pressed == true)
    pos.y -= 1;
}

void Player::draw() {
  ofSetColor(0, 0, 0);
  ofDrawCircle(pos.x, pos.y, 50);
}

void Player::calculate_movement() {}
