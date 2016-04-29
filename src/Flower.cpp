//
//  Flower.cpp
//  flowers4
//
//  Created by eden on 4/25/16.
//
//

#include "Flower.hpp"

ofImage Flower::flower_1;
ofImage Flower::flower_2;
ofImage Flower::flower_3;
ofImage Flower::flower_4;
ofImage Flower::flower_5;
ofImage Flower::flower_6;
ofImage Flower::flower_7;
ofImage Flower::flower_8;
ofImage Flower::flower_9;

ofImage Flower::BW1;
ofImage Flower::BW2;
ofImage Flower::BW3;
ofImage Flower::BW4;
ofImage Flower::BW5;
ofImage Flower::BW6;
ofImage Flower::BW7;

Flower::Flower(){
    
// MODES
    tri = true;
    cFlowers = false;
    wFlowers = true;
    
    dice = ofRandom(7);
    r = ofRandom(100, 200);
    g = ofRandom(100, 200);
    b = ofRandom(100, 200);
    
    birthTime = ofGetElapsedTimeMillis();
    
    isAlive = true;
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
}

void Flower::setup() {
    
    if(!flower_1.isAllocated()) {
        flower_1.load("flowers_1.png");
        flower_2.load("flower_2.png");
        flower_3.load("flower_3.png");
        flower_4.load("flower_4.png");
        flower_5.load("flower_5.png");
        flower_6.load("flower_6.png");
        flower_7.load("flower_7.png");
        flower_8.load("flower_8.png");
        flower_9.load("flower_9.png");
        
        BW1.load("BWflowers1.png");
        BW2.load("BWflowers2.png");
        BW3.load("BWflowers3.png");
        BW4.load("BWflowers4.png");
        BW5.load("BWflowers5.png");
        BW6.load("BWflowers6.png");
        BW7.load("BWmoon.png");

    }
}

void Flower::update(){

// flowers "die" after 5 seconds
    if (ofGetElapsedTimeMillis() - birthTime > 5000) {
        isAlive = false;
    }
}

void Flower::draw(){
    
// flowers fade as the die
    long timeDiff = ofGetElapsedTimeMillis() - birthTime;
    float alpha = ofNormalize(timeDiff, 5000, 0);
    
    ofEnableAlphaBlending();
    
// TRIANGLES / CIRCLES
    
    if (tri == true){
        
    ofFill();
    ofSetColor(r, g, b, 255 * alpha);
    ofSetCircleResolution(20);
    ofDrawCircle(pos.x, pos.y, 35);}
    
// COLOR FLOWERS
    
    if (cFlowers == true){
    ofSetColor(255, 255, 255, 255 * alpha);
    if(dice == 0){
        flower_1.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 1){
        flower_2.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 9){
        flower_3.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 3){
        flower_4.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 4){
        flower_5.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 5){
        flower_6.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 6){
        flower_7.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 2){
        flower_8.draw(pos.x-50, pos.y-50, 100, 100);
    }
    if(dice == 8){
        flower_9.draw(pos.x-50, pos.y-50, 100, 100);
    }

    }
    
// WHITE FLOWERS
    if (wFlowers == true) {
    ofSetColor(255, 255, 255, 255 * alpha);
    
    if(dice == 0){
        BW1.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 1){
        BW2.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 2){
        BW3.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 3){
        BW4.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 4){
        BW5.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 5){
        BW6.draw(pos.x-25, pos.y-25, 50, 50);
    }
    if(dice == 6){
        BW7.draw(pos.x-25, pos.y-25, 50, 50);
        }
    }
    ofDisableAlphaBlending();
};