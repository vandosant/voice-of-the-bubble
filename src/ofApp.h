#pragma once

#include "ofxiOS.h"
#include "bubble.hpp"
#include "particleSystem.hpp"

class ofApp : public ofxiOSApp {

    public:
        void setup();
        void update();
        void draw();
        void exit();

        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);

    vector<Bubble> bubbles;
    vector<Bubble> bubblesForRemoval;
    vector<ParticleSystem> particleSystems;
    ofVec2f G, W;
};
