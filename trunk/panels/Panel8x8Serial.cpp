// Panel8x8 Library
// Simplifies programming the 8x8 LED Panel avaialable from ModernDevice.Com
// This version adds serial support
// See Examples and ReadMe.TXT
// Kits & Schematics available at ModernDevice.Com
//
// By Dataman aka Charley Jones, 8x8Panel@CRJones.Com
// 2009-09-17 Initial Version
#include "Panel8x8Serial.h"

void Panel8x8Serial::About() {
  Serial << "Panel8x8Serial " << PANEL8X8SERIALMAJOR << "." << PANEL8X8SERIALMINOR << endl;
  Panel8x8::About();
}

// CheckSerial
// Checks for commands on the serial port
int Panel8x8Serial::CheckSerial() {
  int i,j,k;
  uint8_t     sr;
  uint16_t    *ptr;  
  static byte sCommand = 0;
  static byte inbuffer[16];
  
  if (Serial.available()>0) {
   while (Serial.available()>0) {
     sr  = Serial.read();
     
     // Look for start of command
     if (sr==27 && sCommand==0) {
       sCommand = 1;
     }
     
     // Command processing
     // If HaveCommand then we saw an escape which is a start of command sequence character
     // Look for Esc-C, Esc-F, Esc-L, or ESC-S
     else if (sCommand == 1) {
       if      (sr=='C') {WriteByte(0,0); iBufferLen=0; NewMessage(); sCommand=0;}
       else if (sr=='T') {PanelMode=11; sCommand=1;} //Loading Text
       else if (sr=='F') {PanelMode=12; sCommand=2;} //Loading Animation
       else if (sr=='L') {PanelMode=13; sCommand=3;} //Live Animation
       else if (sr=='S') {              sCommand=4;} //Settings mode
       //Serial << "Command Decoded " << _DEC(sCommand) << endl;
       i=0;  //Index into char text buffer
       j=0;  //Packet length
       k=0;  //Parameters buffer length
     }
     
     // Text Loading 
     else if (sCommand == 1) { //Text Loading Mode
      if (k++<2) {
       inbuffer[k]=char(sr);  
      }  
      else if (k==2) {
       k++;
       bIsScrolling=true;
       ptr = (uint16_t *)inbuffer;
       j = *ptr;
       if (j==0) {PanelMode=1; NewMessage(); sCommand=0;}   // End of processing if 0 length buffer
      }
      else {
       WriteByte(i++,sr); 
       if (--j==0) {WriteByte(i,0); iBufferLen=i; PanelMode=1; NewMessage(); sCommand=0;} // End of processing if no more text
      }
     }
     
     // Animation Loading
     else if (sCommand == 2) { // Live Animation Load Mode
      // Parameter Processing
      if (k<=7) {
        //Serial << "Param: " << _DEC(k) << " = " << _DEC(sr) << endl;
        inbuffer[k++]=char(sr);  
        if (k==8) { // Parameters
         idxScroll=0;     //Reset buffer pointer
         bIsScrolling=false;
         ptr = (uint16_t *)inbuffer;
         i = *(ptr++);
         //Serial << "Version: " << _DEC(i) << endl;
         if (i!=PANEL8X8SERIALFILE) {Serial.print(char(1)); PanelMode=2; sCommand=0;}  //Send back a 1 as error, wrong version.
         iPanels = *(ptr++);
         iFrames = *(ptr++);
         frameDelay = *(ptr);
         //Serial << "Panels: " << iPanels << endl;
         //Serial << "Fames: " << iFrames << endl;
         //Serial << "Delay: " << frameDelay << endl;
         l = iPanels * 8 * iFrames;
         i=0;
         if (l==0) {Serial.print(char(1)); PanelMode=2; sCommand=0;}   // End of processing if 0 length buffer
        }
      }
      // Data Processing
      else {
       WriteByte(i++,sr); 
       if (i==l) {Serial.print(char(0)); PanelMode=2; sCommand=0;} // End of processing no more data.
      }
     }
     
     // Live Animation Loading
     else if (sCommand == 3) { // Live Animation Load Mode
      // Parameter Processing
      if (k<=5) {
        //Serial << "Param: " << _DEC(k) << " = " << _DEC(sr) << endl;
        inbuffer[k++]=char(sr);  
        if (k==6) { // Parameters
         idxScroll=0;     //Reset buffer pointer
         bIsScrolling=false;
         ptr = (uint16_t *)inbuffer;
         i = *(ptr++);
         //Serial << "Version: " << _DEC(i) << endl;
         if (i!=PANEL8X8SERIALFILE) {Serial.print(char(1)); PanelMode=3; sCommand=0;}  //Send back a 1 as error, wrong version.
         iPanels = *(ptr++);
         iFrames = 1;
         frameDelay = *(ptr);
         //Serial << "Panels: " << iPanels << endl;
         //Serial << "Fames: " << iFrames << endl;
         //Serial << "Delay: " << frameDelay << endl;
         l = iPanels * 8;
         j = 0;
         i = 0;
         if (l==0) {PanelMode=3; sCommand=0;}   // End of processing if 0 length buffer
        }
      }
      // Data Processing
      else {
      //Serial << _DEC(l) << ":" << _DEC(sr) << endl;
       iScroll[j][i++] = sr;
       if (i==8) {i=0; j++;} 
       --l;
       if (l==0) {Serial.print(char(0)); PanelMode=3; sCommand=0; Scroll();} // End of processing no more data.
      }
     }
     
     // Settings commands
     else if (sCommand == 4) {
         if      (sr==0) {Begin((char *)ramBuffer,iBufferSize,iBufferLen,(int)isBufferProgMem); sCommand=0;}
         else if (sr==1) {frameDelay = sr; sCommand=0;}
         else if (sr==2) {sCommand=0;}
     }
   }
  }
}

int Panel8x8Serial::WriteByte(int idx, byte iBtye) {
  if (isBufferProgMem) {return -1;}
  *(ramBuffer+idx)=iBtye;
  return 0;
}
 




