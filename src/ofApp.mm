#include "ofApp.h"

bool isOutsideWindow(Bubble b) {
    return (b.location.x > ofGetWindowWidth() + b.mass) ||
    (b.location.y > ofGetWindowHeight() + b.mass);
}

//--------------------------------------------------------------
void ofApp::setup(){	
    ofEnableAlphaBlending();
    G = ofVec2f(0,0.1);
    W = ofVec2f(0.0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    if ((int)ofGetElapsedTimeMillis() % 20 == 0) {
        Bubble b;
        int x = 0;
        int y = 0;
        float mass = ofRandom(20, 35);
        if (ofRandom(1) > 0.5) {
            x = ofRandom(0, ofGetWindowWidth());
        } else {
            y = ofRandom(0, ofGetWindowHeight());
            
        }
        b.setup(ofVec2f(x, y), mass);
        bubbles.push_back(b);
    }
    
    for (auto &b: bubbles) {
        b.applyForce(G);
        b.applyForce(W);
        b.update();
    }
    
    for (auto &p: particleSystems) {
        
        p.update();
    }
    
    bubbles.erase( std::remove_if( bubbles.begin(), bubbles.end(), isOutsideWindow ), bubbles.end() );
    particleSystems.erase( std::remove_if( particleSystems.begin(), particleSystems.end(), [&](ParticleSystem &p) {
        return p.isDead();
    }), particleSystems.end() );
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for (auto &b: bubbles) {
        b.display();
    }
    for (auto &p: particleSystems) {
        p.display();
    }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    ofVec2f mouseLocation = ofVec2f(touch.x, touch.y);
    for (auto &b: bubbles) {
        if (b.location.distance(mouseLocation) < b.mass) {
            bubblesForRemoval.push_back(b);
        }
    }
    
    for (auto &b: bubblesForRemoval) {
        ParticleSystem p;
        p.setup(b.location, b.mass, b.velocity);
        particleSystems.push_back(p);
    }
    
    bubblesForRemoval.clear();
    
    bubbles.erase( remove_if( bubbles.begin(), bubbles.end(), [&](Bubble &b) {
        return b.location.distance(mouseLocation) < b.mass;
    }), bubbles.end() );
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
