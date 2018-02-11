//
//  bubble.cpp
//  voicesOfTheBubble
//
//  Created by Scott Skender on 1/8/18.
//
//

#include "bubble.hpp"

void Bubble::setup(ofVec2f l, float m) {
    location = l;
    mass = m;
}

void Bubble::update() {
    float x = ofMap(sin(angle), -1, 1, -0.1, 0.1);
    applyForce(ofVec2f(x, 0));
    velocity = velocity + acceleration;
    location = location + velocity;
    if (velocity.x > maxVelocity) {
        velocity.x = maxVelocity;
    }
    if (velocity.y > maxVelocity) {
        velocity.y = maxVelocity;
    }
    angle += 0.05;
}

void Bubble::display() {
    ofSetColor(color);
    ofFill();
    ofSetCircleResolution(22 + (22 % (int)mass));
    ofDrawCircle(location.x,location.y,mass);
}

void Bubble::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration = acceleration + f;
}
