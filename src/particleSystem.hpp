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
        void setup(ofVec2f l, float m);
        void update();
        void display();
        bool isDead();

        float mass = 0;
        float ticksLeft = 100;
        ofVec2f location = ofVec2f(0, 0);
        vector<Particle> particles;

        ParticleSystem() { };

    private:
};
#endif /* particleSystem_hpp */
