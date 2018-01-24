//
//  particleSystem.cpp
//  voiceOfTheBubble
//
//  Created by Scott Skender on 1/20/18.
//
//

#include "particleSystem.hpp"

void ParticleSystem::setup(ofVec2f l, float m, ofVec2f currentVelocity) {
    location = l;
    mass = m;
    float modifier = 18;
    for (int i = 0; i <= 360; i+=modifier) {
        Particle p;
        ofVec2f v = currentVelocity + ofVec2f(cos(i)/2, sin(i)/2);
        ofVec2f a = ofVec2f(cos(i)/2, sin(i)/2);
        ofVec2f particleLocation = ofVec2f(location.x + (cos(i)*m), location.y + sin(i)*m);
        p.setup(particleLocation, v, lifespan, ofRandom(0, 90));
        p.applyForce(a);
        particles.push_back(p);
    }
}

void ParticleSystem::update() {
    for (auto &p: particles) {
        p.update();
    }

    lifespan--;
}

void ParticleSystem::display() {
    for (auto &p: particles) {
        p.display();
    }
}

bool ParticleSystem::isDead() {
    return lifespan <= 0;
}
