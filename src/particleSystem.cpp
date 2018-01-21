//
//  particleSystem.cpp
//  voiceOfTheBubble
//
//  Created by Scott Skender on 1/20/18.
//
//

#include "particleSystem.hpp"

void ParticleSystem::setup(ofVec2f l, float m) {
    location = l;
    mass = m;
}

void ParticleSystem::update() {
    mass += 0.05;
}

void ParticleSystem::display() {
    ofSetColor(255,255,255);
    ofDrawLine(location.x,location.y, location.x + mass, location.y + mass);
}

void ParticleSystem::applyForce(ofVec2f force) {

}
