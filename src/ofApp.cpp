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
        float mass = ofRandom(25, 40);
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

    for (auto &p: particles) {
        p.update();
    }

    bubbles.erase( std::remove_if( bubbles.begin(), bubbles.end(), isOutsideWindow ), bubbles.end() );
    particles.erase( std::remove_if( particles.begin(), particles.end(), [&](ParticleSystem &p) {
        return p.isDead();
    }), particles.end() );
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for (auto &b: bubbles) {
        b.display();
    }
    for (auto &p: particles) {
        p.display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofVec2f mouseLocation = ofVec2f(x, y);
    for (auto &b: bubbles) {
        if (b.location.distance(mouseLocation) < b.mass) {
            bubblesForRemoval.push_back(b);
        }
    }

    for (auto &b: bubblesForRemoval) {
        ParticleSystem p;
        p.setup(b.location, b.mass);
        particles.push_back(p);
    }

    bubblesForRemoval.clear();

    bubbles.erase( remove_if( bubbles.begin(), bubbles.end(), [&](Bubble &b) {
        return b.location.distance(mouseLocation) < b.mass;
    }), bubbles.end() );
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
