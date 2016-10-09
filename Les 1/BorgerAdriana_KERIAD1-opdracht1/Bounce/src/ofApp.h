#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

private:
	float x1;
	float x2;
	float x3;
	float x4;

	float y1;
	float y2;
	float y3;
	float y4;

	float speedX1;
	float speedX2;
	float speedX3;
	float speedX4;

	float speedY1;
	float speedY2;
	float speedY3;
	float speedY4;

	int radius1;
	int radius2;
	int radius3;
	int radius4;

	ofColor color1;
	ofColor color2;
	ofColor color3;
	ofColor color4;
};