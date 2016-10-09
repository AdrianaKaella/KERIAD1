#pragma once

#include "ofMain.h"

class Planet
{
    public:
        Planet();
        virtual ~Planet();
        void setup(string name);
        void update();
        void draw();

        ofParameterGroup planetParamGroup;
        ofParameter<float> rotateSpeed;
        ofParameter<float> distance;
        ofParameter<int> red;
        ofParameter<int> green;
        ofParameter<int> blue;

        float rotation;
};
