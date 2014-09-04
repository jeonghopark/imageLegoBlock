#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetDataPathRoot("../Resources/data/");
    
    ofBackground(30);
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    
    legoWhite.loadImage("legoWhite_4.png");
    legoPlatte.loadImage("legoPlatte.jpg");
    
    legoSize = 32;
    legoPixelsNumber = legoSize * legoSize;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (draggedImages.size()>0) {
        
        int _draggedImgNr = draggedImages.size();
        float _draggedImgWidth = draggedImages[_draggedImgNr-1].getWidth();
        float _draggedImgHeight = draggedImages[_draggedImgNr-1].getHeight();
        int _totalPixels = _draggedImgWidth*_draggedImgHeight*3;
        
        int _limitSize = 1024;
        
        if ((_draggedImgWidth>_draggedImgHeight)&&(_draggedImgWidth>_limitSize)) {
            float _hwRatio = _draggedImgHeight/_draggedImgWidth;
            _draggedImgWidth = _limitSize;
            _draggedImgHeight = (int)(_draggedImgWidth * _hwRatio);
            draggedImages[_draggedImgNr-1].resize(_draggedImgWidth, _draggedImgHeight);
        }
        
        if ((_draggedImgHeight>_draggedImgWidth)&&(_draggedImgHeight>_limitSize)) {
            float _whRatio = _draggedImgWidth/_draggedImgHeight;
            _draggedImgHeight = _limitSize;
            _draggedImgWidth = (int)(_draggedImgHeight * _whRatio);
            draggedImages[_draggedImgNr-1].resize(_draggedImgWidth, _draggedImgHeight);
        }
        
        legoPicWidth = _draggedImgWidth / legoSize;
        legoPicHeight = _draggedImgHeight / legoSize;
        
        ofSetWindowShape(legoPicWidth*legoSize, legoPicHeight*legoSize);
        
        pixelColorR.resize(_totalPixels/3);
        pixelColorG.resize(_totalPixels/3);
        pixelColorB.resize(_totalPixels/3);
        
        unsigned char * _pixels = draggedImages[_draggedImgNr-1].getPixels();
        
        for (int n=0; n<legoPicHeight; n++) {
            for (int m=0; m<legoPicWidth; m++) {
                
                int _legoPixelIndex = m + n * legoPicWidth;
                
                float _sumColorR = 0;
                float _sumColorG = 0;
                float _sumColorB = 0;
                
                for (int j = _draggedImgWidth*3*legoSize*n; j < _draggedImgWidth*3*legoSize*(n+1); j+=_draggedImgWidth*3) {
                    for (int i = legoSize*3*m; i < legoSize*3*m+legoSize*3; i+=3) {
                        int _index = i + j;
                        _sumColorR += _pixels[_index+0];
                        _sumColorG += _pixels[_index+1];
                        _sumColorB += _pixels[_index+2];
                    }
                }
                
                pixelColorR[_legoPixelIndex] = _sumColorR/legoPixelsNumber;
                pixelColorG[_legoPixelIndex] = _sumColorG/legoPixelsNumber;
                pixelColorB[_legoPixelIndex] = _sumColorB/legoPixelsNumber;
                
            }
        }
        
    }
    
    if (draggedImages.size()>1) {
        draggedImages.erase(draggedImages.begin());
    }
    
}

//--------------------------------------------------------------

void ofApp::draw(){
    
    legoPlatte.draw(0, 0);
    
    if (pixelColorR.size()>0) {
        
        for (int j = 0; j < legoPicHeight; j++){
            for (int i = 0; i < legoPicWidth; i++){
                
                int _index = i + j*legoPicWidth;
                
                ofPushStyle();
                ofSetColor( ofColor(pixelColorR[_index], pixelColorG[_index], pixelColorB[_index], 255) );
                legoWhite.draw(i*legoSize, j*legoSize, legoSize, legoSize);
                ofPopStyle();
            }
        }
        
        for (int j = 0; j < legoPicHeight; j++){
            for (int i = 0; i < legoPicWidth; i++){
                
                int _index = i + j*legoPicWidth;
                
                ofPushStyle();
                ofSetColor( pixelColorG[(legoPicHeight*legoPicWidth)-_index], 30 );
                ofLine(i*legoSize, j*legoSize, i*legoSize, j*legoSize+legoSize);
                ofLine(i*legoSize, j*legoSize, i*legoSize+legoSize, j*legoSize);
                ofPopStyle();
            }
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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
void ofApp::windowResized(int w, int h){
    
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo info){
    
    if( info.files.size() > 0 ){
        dragPt = info.position;
        
        draggedImages.assign( info.files.size(), ofImage() );
        for(unsigned int k = 0; k < info.files.size(); k++){
            draggedImages[k].loadImage(info.files[k]);
        }
    }
    
    
}

