#include "ofApp.h"
#include "Ball.h"

Ball ball;

void ofApp::setup() {
	gui.setup("Instellingen", "settings.xml");
	gui.add(startRadius.set("Radius", 50, 0, 200));
	gui.add(startSpeedX.set("Speed X", 50, 0, 200));
	gui.add(startSpeedY.set("Speed Y", 50, 0, 200));
}

void ofApp::update() {
	ball.update();
}

void ofApp::draw() {
	gui.draw();
	ball.draw();
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		ball.setup(ofRandom(ofGetWidth()),
			ofRandom(ofGetHeight()),
			startRadius,
			startSpeedX,
			startSpeedY);
	}
}