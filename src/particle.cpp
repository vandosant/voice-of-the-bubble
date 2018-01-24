//
//  particles.cpp
//  voiceOfTheParticle
//
//  Created by Scott Skender on 1/21/18.
//
//

#include "particle.hpp"

void Particle::setup(ofVec2f l, ofVec2f v, float life) {
    location = l;
    velocity = v;
    lifespan = life;
}

void Particle::update() {
    velocity = velocity + acceleration;
    location = location + velocity;
    lifespan--;
}

void Particle::display() {
    ofSetColor(ofColor(255, 255, 255, ofMap(lifespan, 0, 100, 0, 255)));
    ofDrawLine(location.x,location.y, location.x + mass, location.y + mass);
}

void Particle::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration = acceleration + f;
}
