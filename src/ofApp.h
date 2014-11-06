#pragma once

#define PRINT_IP 224.0.0.1
#define PRINT_PORT 11370
#define NUM_MSG_STRINGS 20


#include "ofMain.h"
#include "ofxOsc.h"
#include "ito36.h"

class ofApp : public ofBaseApp{

	public:
    
        ofxOscReceiver receiver;
        void listenOsc();
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
    
    
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
