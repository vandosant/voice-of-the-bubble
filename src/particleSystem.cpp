//
//  particleSystem.cpp
//  voiceOfTheBubble
//
//  Created by Scott Skender on 1/20/18.
//
//

#include "particleSystem.hpp"

void ParticleSystem::setup(ofVec2f l, float r, ofVec2f currentVelocity) {
    location = l;
    radius = r;
    float modifier = 18;
    for (int i = 0; i <= 360; i+=modifier) {
        Particle p;
        ofVec2f startingVelocity = ofVec2f(cos(i), sin(i));
        ofVec2f v = startingVelocity * 0.4;
        float x = location.x + cos(i) * radius + ofRandom(-5, 5);
        float y = location.y + sin(i) * radius + ofRandom(-5, 5);
        float angle = ofRandom(0, 90);
        p.setup(ofVec2f(x, y), v, lifespan, angle);
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

void ParticleSystem::applyForce(ofVec2f f) {
    for (auto &p: particles) {
        p.applyForce(f);
    }
}

bool ParticleSystem::isDead() {
    return lifespan <= 0;
}
