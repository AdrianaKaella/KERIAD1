#include "ofApp.h"

#define PIN_BLUE 9
#define PIN_GREEN 10
#define PIN_RED 11


void ofApp::setup() {
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM5"); //stel je eigen Com even goed in
	arduino.sendFirmwareVersionRequest();
}


void ofApp::update() {
	arduino.update();
}

void ofApp::keyPressed(int key)
{
	if (key == 'r') {
		arduino.sendPwm(PIN_RED, 255); //eerste parameter is de pin waar je waarde naartoe stuurt, tweede parameter is de waarde zelf
		arduino.sendPwm(PIN_GREEN, 0);
		arduino.sendPwm(PIN_BLUE, 0);
	}

	if (key == 'g') {
		arduino.sendPwm(PIN_RED, 0);
		arduino.sendPwm(PIN_GREEN, 255);
		arduino.sendPwm(PIN_BLUE, 0);
	}

	if (key == 'b') {
		arduino.sendPwm(PIN_RED, 0);
		arduino.sendPwm(PIN_GREEN, 0);
		arduino.sendPwm(PIN_BLUE, 255);
	}

}

void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_RED, ARD_PWM); //BELANGRIJK: Stel de tweede parameter in op ARD_PWM! Zo weet het programma dat je de pin als PWM (= waarde tussen 0 en 255) pin gebruikt
	arduino.sendDigitalPinMode(PIN_GREEN, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BLUE, ARD_PWM);
}