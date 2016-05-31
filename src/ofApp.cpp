#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    circ = false;
    
// load flower class
    flowers.setup();

// setup box2D physics
    box2d.init();
    box2d.enableEvents();
    box2d.setGravity(0, 0);
    box2d.setFPS(60);
    box2d.registerGrabbing();

// register the listener so that we get the events
    ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
    
}

//--------------------------------------------------------------
void ofApp::contactStart(ofxBox2dContactArgs &e) {
    if(e.a != NULL) {
        
// make sure they're circles
        if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
            
    ofxBox2dCircle * circleA = (ofxBox2dCircle *)e.a->GetBody()->GetUserData();

// get the position of the collision
        if(circleA != NULL) {
            ofPoint posA = circleA->getPosition();
            float radiusA = circleA->getRadius();
            
// if they collide, draw a flower
        if (ofDist(posA.x, posA.y, posA.x, posA.y) < 10){
                    
            Flower *flower = new Flower();
            flower->pos.x = posA.x;
            flower->pos.y = posA.y;
            flowers.push_back(flower);
                    
// make sure the flowers are being drawn
            ofLog() << "flowers " << flowers.size();
            
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    
    box2d.update();
    
// circles
    if((int)ofRandom(0, 8) == 0) {
        shared_ptr <ofxBox2dCircle> c = shared_ptr <ofxBox2dCircle>(new ofxBox2dCircle);
        c.get()->setPhysics(1, 0.5, 0.9);
        c.get()->setup(box2d.getWorld(), (ofRandom(ofGetWidth())), ofRandom(ofGetHeight()), 20);
        c.get()->setVelocity(ofRandom(-10, 10), ofRandom(-10, 10)); // shoot them;

        c.get()->setData(c.get());
        
        circles.push_back(c);
        
        ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
    }
    
    if (ofGetWindowMode() != OF_WINDOW){
        ofHideCursor();
    }
    else { ofShowCursor();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    for(size_t i=0; i<circles.size(); i++) {
        
        ofFill();
        
        shared_ptr <ofxBox2dCircle> c = shared_ptr <ofxBox2dCircle>(new ofxBox2dCircle);

        ofxBox2dCircle *circleA = (ofxBox2dCircle *)circles[i].get()->getData();
        ofxBox2dCircle *circleB = (ofxBox2dCircle *)circles[i].get()->getData();
        
// circles
        if (circ == true) {
        ofNoFill();
        circles[i].get()->draw();
        }
    }
    
    
// flowers
    for(vector<Flower*>::iterator i = flowers.begin(); i != flowers.end();) {
        Flower *f = (*i);
        f->update();
        if(!f->isAlive) {
            flowers.erase(i);
            delete f;
        }
        else {
            f->draw();
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
// when key 1 is pressed - show ofBox2d circles
    if (key == '1'){
        circ = true;
    }
    if (key == '2'){
        circ = false; 
    }
// take a screenshot
        if(key == 'x'){
            img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
            img.save("flowers_screenshot.png");
        }
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
    Flower *flower = new Flower();
    flower->pos.x = x;
    flower->pos.y = y;
    flowers.push_back(flower);
    ofLog() << "flowers " << flowers.size();
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
