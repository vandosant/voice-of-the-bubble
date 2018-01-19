#include "ofApp.h"

bool isOutsideWindow(Bubble b) {
    return (b.location.x > ofGetWindowWidth()) ||
    (b.location.y > ofGetWindowHeight());
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
        if (ofRandom(1) > 0.5) {
            x = ofRandom(0, ofGetWindowWidth());
        } else {
            y = ofRandom(0, ofGetWindowHeight());

        }
        b.setup(ofVec2f(x, y), ofRandom(20, 40));
        bubbles.push_back(b);
    }

    for (auto &i: bubbles) {
        i.applyForce(G);
        i.applyForce(W);
        i.update();
    }

    bubbles.erase( std::remove_if( bubbles.begin(), bubbles.end(), isOutsideWindow ), bubbles.end() );
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for (auto &i: bubbles) {
        i.display();
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
    bubbles.erase( std::remove_if( bubbles.begin(), bubbles.end(), [&](Bubble &b) {
        ofVec2f mouseLocation = ofVec2f(x, y);
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
