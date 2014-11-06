#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    receiver.setup(PRINT_PORT);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    listenOsc();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::listenOsc(){
    
    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        // check for mouse moved message
        if(m.getAddress() == "/printQR"){
            // both the arguments are int32's
            int id_seed =  m.getArgAsInt32(0);
            char str[16];
            int str_length = ito36( id_seed, str );
            printf("%s\n", str);
            
        }
//        // check for mouse button message
//        else if(m.getAddress() == "/mouse/button"){
//            // the single argument is a string
//            // mouseButtonState = m.getArgAsString(0);
//        }
        
    }
        
}
