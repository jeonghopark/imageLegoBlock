#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //    ofSetDataPathRoot("../Resources/data/");
    
    ofBackground(30);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    video.setup(360, 480, OF_PIXELS_RGB);
    
    legoWhite.load("legoWhite_3.png");
    
    cout << video.getWidth() << " " << video.getHeight() << endl;
    
    legoSize = 10;
    legoPixelsNumber = legoSize * legoSize;
    
    legoPicWidth = 360 / legoSize;  // 48
    legoPicHeight = 480 / legoSize;  // 64
    
    int _totalPixels = legoPicWidth * legoPicHeight;
    
    pixelColorR.resize(_totalPixels);
    pixelColorG.resize(_totalPixels);
    pixelColorB.resize(_totalPixels);

    screenRatio = 1536.0 / video.getWidth();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    video.update();
    
    if(video.isFrameNew() == true) {
        
        //        if (draggedImages.size()>0) {
        
        //            int _draggedImgNr = draggedImages.size();
        //            float _draggedImgWidth = draggedImages[_draggedImgNr-1].getWidth();
        //            float _draggedImgHeight = draggedImages[_draggedImgNr-1].getHeight();
        //
        //            int _limitSize = 1024;
        //
        //            if ((_draggedImgWidth>_draggedImgHeight)&&(_draggedImgWidth>_limitSize)) {
        //                float _hwRatio = _draggedImgHeight/_draggedImgWidth;
        //                _draggedImgWidth = _limitSize;
        //                _draggedImgHeight = (int)(_draggedImgWidth * _hwRatio);
        //                draggedImages[_draggedImgNr-1].resize(_draggedImgWidth, _draggedImgHeight);
        //            }
        //
        //            if ((_draggedImgHeight>_draggedImgWidth)&&(_draggedImgHeight>_limitSize)) {
        //                float _whRatio = _draggedImgWidth/_draggedImgHeight;
        //                _draggedImgHeight = _limitSize;
        //                _draggedImgWidth = (int)(_draggedImgHeight * _whRatio);
        //                draggedImages[_draggedImgNr-1].resize(_draggedImgWidth, _draggedImgHeight);
        //            }
        //
        //            legoPicWidth = _draggedImgWidth / legoSize;
        //            legoPicHeight = _draggedImgHeight / legoSize;
        //
        //            ofSetWindowShape(legoPicWidth*legoSize, legoPicHeight*legoSize);
        //

        
        unsigned char * _pixels = video.getPixels().getData();
        
        float _sumColorR = 0;
        float _sumColorG = 0;
        float _sumColorB = 0;

        pixelColorR.clear();
        pixelColorG.clear();
        pixelColorB.clear();

        
        for (int n=0; n<legoPicHeight; n+=1) {
            for (int m=0; m<legoPicWidth; m+=1) {
                
                int _legoPixelIndex = (n * legoPicWidth * legoSize + m) * 3 * legoSize;
                
                _sumColorR = _pixels[_legoPixelIndex + 0];
                _sumColorG = _pixels[_legoPixelIndex + 1];
                _sumColorB = _pixels[_legoPixelIndex + 2];
                
                
                pixelColorR.push_back(_sumColorR);
                pixelColorG.push_back(_sumColorG);
                pixelColorB.push_back(_sumColorB);
                
            }
        }
        

        //        }
        
        
    }
    
    
}

//--------------------------------------------------------------

void ofApp::draw(){
    
//    legoPlatte.draw(0, 0);
    
    if (pixelColorR.size()>0) {
        
        for (int i = 0; i < legoPicHeight; i++){
            for (int j = 0; j < legoPicWidth; j++){
            
                int _index = j + i * legoPicWidth;
                
                ofPushStyle();
                ofSetColor( ofColor(pixelColorR[_index], pixelColorG[_index], pixelColorB[_index], 255) );
                
                float _x = j * legoSize * screenRatio;
                float _y = i * legoSize * screenRatio;
                float _size = legoSize * screenRatio;
                legoWhite.draw(_x, _y, _size, _size);
                ofPopStyle();
                
            }
        }
        
//        for (int j = 0; j < legoPicWidth; j++){
//            for (int i = 0; i < legoPicHeight; i++){
//                
//                int _index = j + i * legoPicWidth;
//                
//                ofPushStyle();
//                ofSetColor( pixelColorG[(legoPicHeight*legoPicWidth)-_index], 30 );
//                ofLine(i*legoSize, j*legoSize, i*legoSize, j*legoSize+legoSize);
//                ofLine(i*legoSize, j*legoSize, i*legoSize+legoSize, j*legoSize);
//                ofPopStyle();
//            }
//        }
        
    }
    
    
}


//--------------------------------------------------------------
void ofApp::exit(){
    
}


//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    
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
