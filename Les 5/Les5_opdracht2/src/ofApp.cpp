#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
    ofSetFrameRate(60);

    ofBackground(30, 30, 30);

    drawGrid = false;

    planet01.setup("planet 1");
    planetParams.add(planet01.planetParamGroup);

    planet02.setup("planet 2");
    planetParams.add(planet02.planetParamGroup);

    planet03.setup("planet 3");
    planetParams.add(planet03.planetParamGroup);

    gui.setup(planetParams);
    gui.add(drawLight.set("Light", false));
    gui.add(drawGrid.set("Grid", false));
    gui.add(useLight.set("Use lighting", true));

    light.setDirectional();
    light.setPosition(-200, -200, -200);
    light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
    light.setDiffuseColor(ofColor(255, 255, 255));
    light.enable();

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
	arduino.update();
    planet01.update();
    planet02.update();
    planet03.update();
}

void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
	arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

	}

void ofApp::digitalPinChanged(const int& pin) {
	int value = arduino.getDigital(pin);
	ofLog() << "Knop" /*<< pin << */" = " << value << endl;
	//in dit geval is er maar 1 digital pin en kan ik deze dus "knop" noemen

	if (value == 1) {
		ofLog() << "distance" /*<< pin << */" = " << planet03.distance << endl;

		planet02.distance += 40.0;
		planet03.distance += 25.0;
	}
}

void ofApp::analogPinChanged(const int& pin) {
	int value = arduino.getAnalog(pin);
	//ofLog() << "Potmeter"/* << pin << */" = " << value << endl;
	//in dit geval is er maar 1 analog pin en kan ik deze dus "potmeter" noemen

	float potSpeed02 = ofMap(value, 1023, 0, planet02.rotateSpeed.getMin(), planet02.rotateSpeed.getMax());
	float potSpeed03 = ofMap(value, 1023, 0, 0, 9);

	planet02.rotateSpeed = potSpeed02;
	planet03.rotateSpeed = potSpeed03;

	//ofLog() << "Potmeter"/* << pin << */" = " << potSpeed02 << endl;
}

void ofApp::draw() {
    gui.draw();

    if (useLight) {
        ofEnableLighting();
    } else {
        ofDisableLighting();
    }

    ofEnableDepthTest();
    cam.begin();

    if (drawLight) light.draw();
    if (drawGrid) ofDrawGrid(200);

    planet01.draw();

    ofTranslate(planet01.distance, 0);
    planet02.draw();

    ofTranslate(planet02.distance,0);
    planet03.draw();

    cam.end();
    ofDisableDepthTest();
}

void ofApp::keyPressed(int key) {
    if (key == 'g') {
        drawGrid = !drawGrid;
    } else if (key == 'l') {
        drawLight = !drawLight;
    } else if (key == 'k') {
        useLight = !useLight;
    }
}
