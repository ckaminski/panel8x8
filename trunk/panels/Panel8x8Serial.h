// Panel8x8 Library
// Simplifies programming the 8x8 LED Panel avaialable from ModernDevice.Com
// See Examples and ReadMe.TXT
// Kits & Schematics avaialbe at ModernDevice.Com
//
// By Dataman aka Charley Jones, 8x8Panel@CRJones.Com
// 2009-09-17 Initial Version
#ifndef Panel8x8Serialb_h
#define Panel8x8Serailb_h

#include <Panel8x8.h>                // Header to access Panel8x8 Library
//#include "avr/pgmspace.h"            // Header to access ProgMem
//#include "..\Streaming\Streaming.h"  // Header to allow streaming operations String << "TEST"; Simplifies output.
//#include "..\String\WString.h"       // Header to allow string operations


// -------------------- DEFINES ---------------------------

// Switches, uncomment to enable and disable functionality
//#define PANEL8X8_DUMPPANELS          // Dumps panel data to serial line after each loop
//#define PANEL8X8_NO_CHDATA           // Saves 760 of progmem by omitting text from Rom space, 
//                                        no text scrolling though.

// Configuration

// Animation File Version
#define PANEL8X8SERIAL   1            // Current library version

// Defines

class Panel8x8Serial::public Panel8x8 { 

    Panel8x8Serial
	 :Panel8x8() {
  	  Serial.Beign(57600);
    }

	//Begin(char *buffer, int bufsize, int buflen, int isProgMem):
    //  Panel8x8::Begin(buffer,bufsize,buflen,isProgMem){
	//	PanelMode = 3;
	//}

    void loop(){
		if (!CheckSerial()) {
			Panel8x8::loop();
		}
	}

	int CheckSerial();
};

#endif Panel8x8Serialb_h
