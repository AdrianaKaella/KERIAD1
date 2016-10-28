#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();

private:
	ofArduino arduino;

	void setupArduino(const int& version);

};
