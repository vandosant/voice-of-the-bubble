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

class ParticleSystem {
public:
    
    void setup(ofVec2f l, float m);
    void update();
    void display();
    void applyForce(ofVec2f force);
    
    float mass = 0;
    ofVec2f location = ofVec2f(0, 0);
    
    ParticleSystem() { };
    
private:
};
#endif /* particleSyste_hpp */
