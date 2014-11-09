#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    //OSC
    receiver.setup(PRINT_PORT);

    
    //Serial
    ofSetVerticalSync(true);
    bSendSerialMessage = false;
    ofSetLogLevel(OF_LOG_VERBOSE);

    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
//    serial.setup(0, baud); //open the first device
    //serial.setup("COM4", baud); // windows example
    //serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
    //serial.setup("/dev/ttyUSB0", baud); //linux example

    //137 Ratina
    //    serial.setup("/dev/tty.usbmodem1451", baud);
    // 137 MBP15
        serial.setup("/dev/tty.usbmodem621", baud);
    
    
    nTimesRead = 0;
    nBytesRead = 0;
    readTime = 0;
    memset(bytesReadString, 0, 4);
    
//    unsigned char buf[4] = {'o', 'f', '!', 0x0A};
//    serial.writeBytes(&buf[0], 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    listenOsc();
    
//    //Serial
//    if (bSendSerialMessage){
//        
//        // (1) write the letter "a" to serial:
//        //serial.writeByte('a');
////        unsigned char buf[4] = {'o', 'f', '!', 0x0A};
////        serial.writeBytes(&buf[0], 4);
//        
//        // (2) read
//        // now we try to read 3 bytes
//        // since we might not get them all the time 3 - but sometimes 0, 6, or something else,
//        // we will try to read three bytes, as much as we can
//        // otherwise, we may have a "lag" if we don't read fast enough
//        // or just read three every time. now, we will be sure to
//        // read as much as we can in groups of three...
//        
////        nTimesRead = 0;
////        nBytesRead = 0;
////        int nRead  = 0;  // a temp variable to keep count per read
////        
////        unsigned char bytesReturned[3];
////        
////        memset(bytesReadString, 0, 4);
////        memset(bytesReturned, 0, 3);
////        
////        while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
////            nTimesRead++;
////            nBytesRead = nRead;
////        };
////        
////        memcpy(bytesReadString, bytesReturned, 3);
////        
//        bSendSerialMessage = false;
//        readTime = ofGetElapsedTimef();
//    }
    
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
//            printf("%s\n", str);
            this->writeSerial(str, str_length);
            
        }

        
    }
        
}


//--------------------------------------------------------------
void ofApp::writeSerial(char *created_id, int id_len){

    
    char slash[]="/";
    char lb[]="\n";
    char basic_url[40] = "http://cell.sonilab.org/";
    int url_len =24;
    
    strcat(basic_url, created_id);
    strcat(basic_url, slash);
    strcat(basic_url, lb);
    int total_len = url_len + id_len + 2; // 2= slash and linebreak
    
    //Copy the creared url to buffer
    unsigned char buf[40];
    for (int i=0; i<40; i++){
        
        buf[i] = basic_url[i];
        
    }
    cout << basic_url;
    serial.writeBytes(&buf[0],total_len);
    
//    unsigned char buf[40] = basic_url;
//    serial.writeBytes(&buf[0], 4);
    
    
}
