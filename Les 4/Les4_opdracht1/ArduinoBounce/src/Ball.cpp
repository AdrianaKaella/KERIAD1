#include "Ball.h"

Ball::Ball() {
}

void Ball::setup(int mySpeedX, int mySpeedY, int myRadius, ofColor myColour) {
	x = ofRandom(0, ofGetWidth());        // give some random position
	y = ofRandom(0, ofGetHeight());

	speedX = mySpeedX;           // and random speed and direction
	speedY = mySpeedY;

	radius = myRadius;

	color = myColour;
}


void Ball::update() {
	if (x < 0) {
		x = 0;
		speedX *= -1;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX *= -1;
	}

	if (y < 0) {
		y = 0;
		speedY *= -1;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY *= -1;
	}

	x += speedX;
	y += speedY;
}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}