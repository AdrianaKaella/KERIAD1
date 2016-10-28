#include "ofApp.h"

//Vaste pins voor RGB en IR proximity meter definieren
#define PIN_BLUE 9
#define PIN_GREEN 10
#define PIN_RED 11
#define PIN_IRP 0


void ofApp::setup() {

	//Arduino initializen
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM5"); //Arduino board uitlezen
	arduino.sendFirmwareVersionRequest();

}


void ofApp::update() {

	arduino.update();

	//Rauwe waarde IR Proximity Sensor uitlezen en naar "value" sturen
	int value = arduino.getAnalog(PIN_IRP);
	ofLog() << "Raw = " << value << endl; //waarde printen

	//Blauw (koud)
	//Waardes van afstand 0 - 250 omzetten naar een blauwe kleurcode. Hoe dichterbij, hoe meer richting oranje.
	int ledRedA = ofMap(value, 0, 250, 150, 230);
	int ledGreenA = ofMap(value, 0, 250, 150, 50);
	int ledBlueA = ofMap(value, 0, 250, 255, 40);

	//Paars-achtig (warmer)
	//Waardes van afstand 250 - 550 omzetten naar een kleurcode tussen blauw en rood in. Hoe dichterbij, hoe meer richting oranje.
	int ledRedB = ofMap(value, 250, 550, 230, 240);
	int ledGreenB = ofMap(value, 250, 550, 50, 30);
	int ledBlueB = ofMap(value, 250, 550, 40, 25);

	//Rood-oranje (warmst)
	//Waardes van afstand 450 - 700 omzetten naar een rood-oranje kleurcode. Hoe dichterbij, hoe roder.
	int ledRedC = ofMap(value, 450, 700, 240, 255);
	int ledGreenC = ofMap(value, 450, 700, 30, 15);
	int ledBlueC = ofMap(value, 450, 700, 25, 0);


	//Als de waarde (afstand) onder 250 zit, wordt de A-waarde doorgestuurd naar de RGB ledjes
	if (value < 250) {
		arduino.sendPwm(PIN_RED, ledRedA);
		arduino.sendPwm(PIN_GREEN, ledGreenA);
		arduino.sendPwm(PIN_BLUE, ledBlueA);
	}

	//als de waarde boven 250 zit, wordt de B-waarde doorgestuurd naar de RGB ledjes
	else {
		arduino.sendPwm(PIN_RED, ledRedB);
		arduino.sendPwm(PIN_GREEN, ledGreenB);
		arduino.sendPwm(PIN_BLUE, ledBlueB);

		//als de waarde tussen 450 en 700 zit, wordt de C-waarde doorgestuurd naar de RGB ledjes
		//bewust in een andere if-statement gezet zodat de code niet constant hoeft te kijken of er ook nog een tussenwaarde is, maar dit alleen doet als hij zeker weten al in die tussenwaarde zit.
		if (value > 450 && value < 700) {
			arduino.sendPwm(PIN_RED, ledRedC);
			arduino.sendPwm(PIN_GREEN, ledGreenC);
			arduino.sendPwm(PIN_BLUE, ledBlueC);
		}
	}

}

void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduino initialized" << endl; //Laat weten wanneer de Arduino aangesloten/herkent is
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	//RGB pins definieren als pwm (0-255) output pins
	arduino.sendDigitalPinMode(PIN_RED, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_GREEN, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BLUE, ARD_PWM);
	//IR Proximity Sensor definieren als Analog input pin
	arduino.sendAnalogPinReporting(PIN_IRP, ARD_ANALOG);
}
