//
//  particles.hpp
//  voiceOfTheParticle
//
//  Created by Scott Skender on 1/21/18.
//
//

#ifndef _PARTICLE
#define _PARTICLE

#include "ofMain.h"

class Particle {
public:
    
    void setup(ofVec2f l, ofVec2f v, float life);
    void update();
    void display();
    void applyForce(ofVec2f force);
    
    float mass = 4;
    float lifespan = 0;
    ofVec2f location = ofVec2f(0, 0);
    ofVec2f velocity = ofVec2f(0, 0);
    ofVec2f acceleration = ofVec2f(0, 0);
    
    Particle() { };
    
private:
};
#endif /* particle_hpp */
