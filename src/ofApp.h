#pragma once

#define PRINT_IP 224.0.0.1
#define PRINT_PORT 11370
#define NUM_MSG_STRINGS 20


#include "ofMain.h"
#include "ofxOsc.h"
#include <string.h>
#include "ito36.h"

class ofApp : public ofBaseApp{

	public:
    
        //OSC Receive
        ofxOscReceiver receiver;
        void listenOsc();
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
        //Serial
        bool		bSendSerialMessage;			// a flag for sending serial
        char		bytesRead[3];				// data from serial, we will be trying to read 3
        char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
        int			nBytesRead;					// how much did we read?
        int			nTimesRead;					// how many times did we read?
        float		readTime;					// when did we last read?
        
        ofSerial	serial;

        void writeSerial(char *created_id,  int id_len);
    
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
