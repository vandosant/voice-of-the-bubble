//
//  particleSystem.hpp
//  voiceOfTheBubble
//
//  Created by Scott Skender on 1/20/18.
//
//

#ifndef _PARTICLE_SYSTEM
#define _PARTICLE_SYSTEM

#include "ofMain.h"
#include "particle.hpp"

class ParticleSystem {
    public:
        void setup(ofVec2f l, float m, ofVec2f currentVelocity);
        void update();
        void display();
        void applyForce(ofVec2f f);
        bool isDead();

        float radius = 0;
        float lifespan = 100;
        ofVec2f location = ofVec2f(0, 0);
        vector<Particle> particles;

        ParticleSystem() { };

    private:
};
#endif /* particleSystem_hpp */
