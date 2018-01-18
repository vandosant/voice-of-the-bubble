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
    velocity = velocity + acceleration;
    location = location + velocity;
    if (velocity.x > maxVelocity) {
        velocity.x = maxVelocity;
    }
    if (velocity.y > maxVelocity) {
        velocity.y = maxVelocity;
    }
}

void Bubble::display() {
    ofSetColor(color);
    ofFill();
    ofDrawCircle(location.x,location.y,mass);
}

void Bubble::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration = acceleration + f;
}
