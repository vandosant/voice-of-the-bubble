//
//  particles.cpp
//  voiceOfTheParticle
//
//  Created by Scott Skender on 1/21/18.
//
//

#include "particle.hpp"

void Particle::setup(ofVec2f l, ofVec2f v, float life, float a) {
    location = l;
    velocity = v;
    lifespan = life;
    angle = a;
}

void Particle::update() {
    velocity = velocity + acceleration;
    location = location + velocity;
    lifespan--;
    angle+=ofMap(velocity.x+velocity.y, 0, 2, 0, 15);
}

void Particle::display() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(angle);
    ofSetColor(ofColor(255, 255, 255, ofMap(lifespan, 0, 100, 0, 255)));
    ofDrawLine(0, 0, mass, mass);
    ofPopMatrix();
}

void Particle::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration = acceleration + f;
}
