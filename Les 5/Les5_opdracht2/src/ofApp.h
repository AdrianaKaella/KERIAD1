#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Planet.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofxPanel gui;
    ofParameterGroup planetParams;

    Planet planet01;
    Planet planet02;
    Planet planet03;

    ofParameter<bool> drawGrid;
    ofEasyCam cam;
    ofParameter<bool> useLight;
    ofParameter<bool> drawLight;
    ofLight light;


private:
	ofArduino arduino;

	void setupArduino(const int& version);

	void digitalPinChanged(const int& pin);

	void analogPinChanged(const int& pin);

};
