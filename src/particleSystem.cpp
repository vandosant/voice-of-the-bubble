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
    for (int i = 0; i < 360; i+=10) {
        Particle p;
        ofVec2f v = ofVec2f(cos(i), sin(i));
        ofVec2f a = ofVec2f(cos(i)*2, sin(i)*2);
        ofVec2f particleLocation = ofVec2f(location.x + (cos(i)*m), location.y + sin(i)*m);
        p.setup(particleLocation, v, 255);
        p.applyForce(a);
        particles.push_back(p);
    }
}

void ParticleSystem::update() {
    for (auto &p: particles) {
        p.update();
    }

    ticksLeft--;
}

void ParticleSystem::display() {
    for (auto &p: particles) {
        p.display();
    }
}

bool ParticleSystem::isDead() {
    return ticksLeft <= 0;
}
