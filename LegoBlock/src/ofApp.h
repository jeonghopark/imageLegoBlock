#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

class ofApp : public ofxiOSApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);

    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    

    ofImage legoWhite;

    int legoSize;

    int legoPicWidth, legoPicHeight;

    vector <ofImage> draggedImages;
    ofPoint dragPt;

    vector<float> pixelColorR;
    vector<float> pixelColorG;
    vector<float> pixelColorB;
    
    ofImage legoPlatte;
    float legoPixelsNumber;
    
    
    ofVideoGrabber video;
    
    float screenRatio;
    
};

