#include "ofApp.h"

bool isOutsideWindow(Bubble b)
{
    return (b.location.x > 100);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    G = ofVec2f(0,0.1);
    W = ofVec2f(0.0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 2; i++) {
        Bubble b;
        int x = 0;
        int y = 0;
        if (i % 2 == 0) {
            x = ofRandom(0, ofGetWindowWidth());
        }
        if (i % 2 != 0) {
            y = ofRandom(0, ofGetWindowHeight());
        }
        b.setup(ofVec2f(x, y), ofRandom(10, 20));
        bubbles.push_back(b);
    }
    float x = ofMap(sin(angle), -1, 1, -0.1, 0.1);
    for (auto &i: bubbles) {
        i.applyForce(G);
        i.applyForce(W);
        i.applyForce(ofVec2f(x, 0));
        i.update();
    }
    bubbles.erase( std::remove_if( bubbles.begin(), bubbles.end(), isOutsideWindow ), bubbles.end() );
    angle += 0.05;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for (int i = 0; i < 200; i++) {
        bubbles[i].display();
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
