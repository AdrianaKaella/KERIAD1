#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

#define MAXBALLS 15

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

	Ball ball;

	ofxPanel gui;
	ofParameter<int> startRadius;
};
