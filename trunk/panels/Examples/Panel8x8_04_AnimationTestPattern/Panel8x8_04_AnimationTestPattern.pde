// Panel8x8_04_AnimationTestPattern
// Example 04: Manipulating the displays using programming.
//
// I needed something to test that all panels and all pixels were working.
// This example demonstrates a simple test pattern.
// We write directly to the output buffer and then display it.
//
// Kits & Schematics avaialbe at ModernDevice.Com
//
// By Dataman aka Charley Jones, 8x8Panel@CRJones.Com
// 2009-09-17 Initial Version

// Overrides default panel support
// Set this value to the number of physical panels to support
#define PANELS 1

// Save some memory as we won't be needing text display
#define PANEL8X8_NO_CHDATA

// Required include for the Panel8x8 library
#include <Panel8x8.h>

// Declare an object of type Panel8x8
Panel8x8 Panel;

// No need to declare a buffer, 
// We're going to draw directly into the display buffer, Panel.iScroll

// Global value to remember which part of the pattern we are on.
// 0-7 = horizontal line
// 8-15 = vertical line
int iPattern=0;

// Called once by ardruino to setup the sketch
void setup() {
 // Call Panel.Begin to initialize panel buffers
 // Syntax: buffer address, max buffer size, current text size, 0=Ram/1=Flash
 Panel.Begin(0,0,0,0);  // Initialize with no buffers 
 Panel.SetScrolling(0); // turn off scrolling
 Panel.PanelMode=3;     // direct animation mode
 Panel.frameDelay=100;  // speed this up!
 Panel.ClearOutput();
};

// Called repeatedly by arduino
// Loops through pattern 1 line a time
// 0-7 = Horizontal Line, 8-15 = Vertical Line
void loop() {
  int i,j;
  if (iPattern < 8) { //Horizontal
   for (i=0;i<PANELS;i++) {
     for (j=0; j<8; j++) {
      Panel.iScroll[i][j] = 0;
      if (j==iPattern) {Panel.iScroll[i][j]=255;}
     }
     Panel.iScroll[i][iPattern] = 255;
   }
  }
  else {
    for (i=0;i<PANELS;i++) { // Vertical
      for (j=0;j<8;j++) {
        Panel.iScroll[i][j]=0;
        bitSet(Panel.iScroll[i][j],iPattern-8);
      }
    }
  }
  ++iPattern;
  if (iPattern>15) {iPattern=0;}
  Panel.Loop();
};
