// Panel8x8
// Example 08: Update over Wifi
//
// This example demonstrates updating text over wireless.
// This should blow the doors off flexibility!
//
// Notes: Input currently limited to about 100 characters by PSOCK library
// See webserver_wifi.h for define "	char inputbuf[100];"
// Also, still need to decode url encoded strings.
// but heck, it's a start!
//
// The only way I know to hook up the hardware right now is with a duemilanove (2k9 for short)
// Plug AsyncLabs Wifi Shield version 1.0 into 2k9. 
// Pins 4,5,6,7 connect to panel 4,5,6,7 
// Power, Ground connect to panel Power, Ground
// To simplify testing, wifi sets itself up as an unprotected adhoc server at 169.254.1.2, 255.255.0.0
// Just connect to ASYNCLABS, you should automatically apipa as no dhcp, or hardcode yourself to 169.254.1.3, 255.255.0.0
// Then browse to 169.254.1.2
// Short messages for now only please, will hang if you get up near 100 chars.
// Just reset shield to continue.
// NEXT: Easy enough to secure by setting a password,
// setting to infrastrustructure mode.
//
// Kits & Schematics available at ModernDevice.Com
//
// By Dataman aka Charley Jones, 8x8Panel@CRJones.Com
// 2009-10-07 Initial Version

// Please remember to set PANELS to the physical number of
// panels to support in Panel8x8.h -- defaults to 4.
// In most cases for 1-4 panels this won't make any difference.

// Required include for the Panel8x8 library
#include <Panel8x8.h>

// Declare an object of type Panel8x8
Panel8x8 Panel;

// Declare the text to be displayed, in this case, in FLASH 
char buffer[512]={"This is a test, this is only a test."};


/*
 * Web Server
 *
 * A simple web server example using the WiShield 1.0
 */
#include <WiShield.h>

#define WIRELESS_MODE_INFRA	1
#define WIRELESS_MODE_ADHOC	2

// Wireless configuration parameters ----------------------------------------
unsigned char local_ip[] = {169,254,1,2};	// IP address of WiShield
unsigned char gateway_ip[] = {0,0,0,0};	// router or gateway IP address
unsigned char subnet_mask[] = {255,255,0,0};	// subnet mask for the local network
const prog_char ssid[] PROGMEM = {"ASYNCLABS"};		// max 32 bytes

unsigned char security_type = 0;	// 0 - open; 1 - WEP; 2 - WPA; 3 - WPA2

// WPA/WPA2 passphrase
const prog_char security_passphrase[] PROGMEM = {};	// max 64 characters

// WEP 128-bit keys
// sample HEX keys
prog_uchar wep_keys[] PROGMEM = {};
//0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,	// Key 0
//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00,	// Key 1
//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00,	// Key 2
//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00	// Key 3
//};

// setup the wireless mode
// infrastructure - connect to AP
// adhoc - connect to another WiFi device
unsigned char wireless_mode = WIRELESS_MODE_ADHOC;

unsigned char ssid_len;
unsigned char security_passphrase_len;

const prog_char webpage[] PROGMEM = {"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<center><h1>Panel 8x8 WifiServer</h1><form method='get' action='0'>Scroll Text<br /><textarea name='1' rows='4' cols='40'></textarea><br /><input type='submit' name='3' value='submit'></form></center>"};

// Called once by ardruino to setup the sketch
void setup() {
 // Call Panel.Begin to initialize panel buffers
 // Syntax: buffer address, max buffer size, current text size, 0=Ram/1=Flash
 Panel.Begin(buffer,512,strlen(buffer),0);
 WiFi.init();
 Serial.begin(9600);
}

// Called repeatedly by arduino
void loop() {
  // Call Panel.Loop to pump the panels
  Panel.Loop();
  WiFi.run();
}

extern "C" {

void ClearPanelBuffer(void){
Panel.ClearOutput();
Panel.iBufferLen=0;
Serial << "Clear Buffer" << endl;
}

void WritePanelByte(byte b){
if (b=='+') {b=' ';}
buffer[Panel.iBufferLen++]=b;
Serial << b;
}

void NewPanelMessage(void){
buffer[Panel.iBufferLen]=0;
Panel.NewMessage();
Serial << "New Message" << endl;
}

}

