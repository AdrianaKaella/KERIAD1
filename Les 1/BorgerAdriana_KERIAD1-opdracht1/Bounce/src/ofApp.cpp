#include "ofApp.h"

void ofApp::setup() {
	x1 = ofRandom(0, ofGetWidth());
	x2 = ofRandom(0, ofGetWidth());
	x3 = ofRandom(0, ofGetWidth());
	x4 = ofRandom(0, ofGetWidth());

	y1 = ofRandom(0, ofGetHeight());
	y2 = ofRandom(0, ofGetHeight());
	y3 = ofRandom(0, ofGetHeight());
	y4 = ofRandom(0, ofGetHeight());

	speedX1 = ofRandom(-2, 2);
	speedX2 = ofRandom(-2, 2);
	speedX3 = ofRandom(-2, 2);
	speedX4 = ofRandom(-2, 2);

	speedY1 = ofRandom(-2, 2);
	speedY2 = ofRandom(-2, 2);
	speedY3 = ofRandom(-2, 2);
	speedY4 = ofRandom(-2, 2);

	radius1 = ofRandom(10, 40);
	radius2 = ofRandom(10, 40);
	radius3 = ofRandom(10, 40);
	radius4 = ofRandom(10, 40);

	color1 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	color2 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	color3 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	color4 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void ofApp::update() {
	
	//balletje 1
	if (x1 <= 0) {
		x1 = 0;
		speedX1 = -speedX1;
	}
	else if (x1 >= ofGetWidth()) {
		x1 = ofGetWidth();
		speedX1 = -speedX1;
	}

	if (y1 <= 0) {
		y1 = 0;
		speedY1 = -speedY1;
	}
	else if (y1 >= ofGetHeight()) {
		y1 = ofGetHeight();
		speedY1 = -speedY1;
	}


	//balletje2
	if (x2 <= 0) {
		x2 = 0;
		speedX2 = -speedX2;
	}
	else if (x2 >= ofGetWidth()) {
		x2 = ofGetWidth();
		speedX2 = -speedX2;
	}

	if (y2 <= 0) {
		y2 = 0;
		speedY2 = -speedY2;
	}
	else if (y2 >= ofGetHeight()) {
		y2 = ofGetHeight();
		speedY2 = -speedY2;
	}


	//balletje 3
	if (x3 <= 0) {
		x3 = 0;
		speedX3 = -speedX3;
	}
	else if (x3 >= ofGetWidth()) {
		x3 = ofGetWidth();
		speedX3 = -speedX3;
	}

	if (y3 <= 0) {
		y3 = 0;
		speedY3 = -speedY3;
	}
	else if (y3 >= ofGetHeight()) {
		y3 = ofGetHeight();
		speedY3 = -speedY3;
	}


	//balletje 4
	if (x4 <= 0) {
		x4 = 0;
		speedX4 = -speedX4;
	}
	else if (x4 >= ofGetWidth()) {
		x4 = ofGetWidth();
		speedX4 = -speedX4;
	}

	if (y4 <= 0) {
		y4 = 0;
		speedY4 = -speedY4;
	}
	else if (y4 >= ofGetHeight()) {
		y4 = ofGetHeight();
		speedY4 = -speedY4;
	}


	x1 += speedX1;
	x2+= speedX2;
	x3 += speedX3;
	x4 += speedX4;

	y1 += speedY1;
	y2 += speedY2;
	y3 += speedY3;
	y4 += speedY4;
}

void ofApp::draw() {
	//ofSetColor(ofColor::red);
	//ofSetColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));

	ofSetColor(color1);
	ofDrawCircle(x1, y1, radius1);
	ofSetColor(color2);
	ofDrawCircle(x2, y2, radius2);
	ofSetColor(color3);
	ofDrawCircle(x3, y3, radius3);
	ofSetColor(color4);
	ofDrawCircle(x4, y4, radius4);
}

void ofApp::keyPressed(int key) {

}