//
//  bubble.hpp
//  voicesOfTheBubble
//
//  Created by Scott Skender on 1/8/18.
//
//

#ifndef _BUBBLE
#define _BUBBLE

#include "ofMain.h"

class Bubble {
    public:

    void setup(ofVec2f l, float m);
    void update();
    void display();
    void applyForce(ofVec2f force);

    float mass = 10;
    ofColor color = ofColor(67,141,149,188);
    ofVec2f location = ofVec2f(0, 0);
    ofVec2f velocity = ofVec2f(0, 0);
    ofVec2f acceleration = ofVec2f(0, 0);
    float maxVelocity = 2;
    float angle = 0;

    Bubble() { };

    private:
};
#endif /* bubble_hpp */
