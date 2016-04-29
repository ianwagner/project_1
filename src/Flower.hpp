//
//  Flower.hpp
//  flowers4
//
//  Created by eden on 4/25/16.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

class Flower {
    
public:
    
    Flower();

    static void setup();
    
    void update();
    void draw();
    void keyPressed(int key);

    
    ofPoint pos;
    
    long birthTime;

    int dice;
    int r;
    int g;
    int b;
    
    bool isAlive;
    
    bool tri;
    bool cFlowers;
    bool wFlowers;
    
// shared flower images
    static ofImage flower_1;
    static ofImage flower_2;
    static ofImage flower_3;
    static ofImage flower_4;
    static ofImage flower_5;
    static ofImage flower_6;
    static ofImage flower_7;
    static ofImage flower_8;
    static ofImage flower_9;

    static ofImage BW1;
    static ofImage BW2;
    static ofImage BW3;
    static ofImage BW4;
    static ofImage BW5;
    static ofImage BW6;
    static ofImage BW7;
    static ofImage BW8;
    
    static ofImage red;
    
};
