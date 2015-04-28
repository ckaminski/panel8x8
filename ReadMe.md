#Contents of ReadMe.Txt v1.03

# Introduction #

This is the contents of the readme file from version 1.03 contained in the Panels8x8 folder of the archive.  This file discusses how to install and use the library.


# Details #

Contents of ReadMe.TXT from Version 1.03

Panel8x8
Support library for the 8x8 LED Panel
Available from http://ModernDevice.Com

By Dataman, aka Charley Jones, 8x8Panel@CRJones.Com

Version Log:

**2009-09-19 V3 Changed pin outputs to bbb standard**

**2009-09-18 V2 Bug fixes, replace example 4, added example 5**

**2009-09-17 V1 Initial**


Notes:

First, there's the hardware.

To make this work, you'll need one more 8x8 panels from ModernDevice.
Note also that the connections are established when the Panel8x8 is instantiated.

The connections are defined as follows:

#define LATCHPIN     4  // Pin connected to SPI latch

#define OUTPUTENABLE 5  // Pin connected to SPI output enable - high equals off

#define CLOCKPIN     6  // Pin connected to SPI clock

> //  low to write new new data

> //  high to transfer the data to the output buffers

#define DATAPIN      7  // Pin connected to SPI clock

The default connections may be modified by editing the Panel8x8.h header file.
Support for SD cards, ethernet, and wireless is coming, so modifying the default
configuration may possibly make a future update incompatible.

Secondly:

A) Installing the Panel8x8 library.
> (Simplifies programming for the 8x8 panel)
> Copy this entire library to the hardware\libraries folder of your Arduino install.
> This code has been tested with Arduino-017 under Windows.

B) Install the Streaming library.
> (Simplifies pinting)
> Can be found at http://arduiniana.org/libraries/Streaming
> Or for your convenience, drag the Streaming folder from Panel8x8\Support
> into your hardware\libraries folder.

Next, close all Arduino sessions and restart.

SCROLLING TEXT FROM RAM:

The very very basics:

Add the library:

```
#include <Panel8x8.h>
```

Create a panel object:

```
Panel8x8 Panel;
```

Create some data:

```
char *Text[]="Display this text.";
```

Initialize the Panel object:

```
void setup() {
 Panel.Begin(buffer,strlen(Text),strlen(Text),0);
}
```

Now pump the output:

```
void loop() {
 Panel.Loop();
}
```

That's all there is to it!
Basically this is Example 1!

USING FLASH MEMORY:

If you'd rather use flash memory, as the 328's are limited to 2k ram...
You only need 2 changes:

Create some data:

```
prog_uchar Text[]  PROGMEM  = {
  "Display this text.  "
  "Display this text too.  "
}
```

Initialize the Panel object:

```
void setup() {
 Panel.Begin((char *)buffer,strlen((char *)Text),strlen((char *)Text),1);
}
```

Everything else stays the same.
That's Example 2.

ANIMATIONS:

Animations aren't that much more difficult.
And are covered in example 3.
Please note:
I have written a character creator, animation creator, and control panel for the 8x8 panels
Using Microsoft Dot Net.  I'm in the process of converting the code to use the new library.
There will be support for SD cards (much more memory that a tiny arduino), ethernet, and wireless.
More examples and objects to come!

PROGRAMMING:

Now that we have a decent library,
It's a cinch to output directly from the arduino.

Example 4 is a Test Pattern I set up to help me debug build problems.
It draws a servies of 8 horizontal and 8 vertical lines per panel.
Set up your number of panels at the top of the code.

Example 5 was an idea I got from the Modern Device 8x8 Panel Support Forum.
A user wondered if the panels could support a game of life simulation.
I'm happy to say that they can.


**Short List of Switches:**

All define must be set in Panel.h
Override is not working from client code.

#define PANELS       4  // The Max Number of panels (each panel consumes 8 bytes ram buffer spaces + 16 total overhead)

Usage:
Set the number of physical panels by defining PANELS,
Library default is 4, and if only running 2 panels, or 1, will slow you down.
(Library calculates and outputs this many panels to the boards, that's a lot of needless io!)


//#define PANEL8X8\_DUMPPANELS          // Dumps panel data to serial line after each loop

//                                        Does not init serial, must Serial.Begin(57600)
in setup

Usage:

Uncomment to Dump Panel Debug to serial after each loop.


//#define PANEL8X8\_NO\_CHDATA           // Saves 760 of progmem by omitting text from Rom space,

//                                        no text scrolling though.

Usage:

Uncomment to save 3/4k in prog mem if not text scrolling.


**Short List of Properties:**

> byte     iPanels;                  // Current number of panels, this is the animation width, required for animation

> uint16\_t iFrames;                  // Number of animation frames, required for animation

> byte     PanelMode;                // Which mode are the panels in, 1=Text, 2=Animation, 3=Live

> int      frameDelay;               // Default delay between refreshes

> uint8\_t  iScroll[PANELS+2][8](8.md);     // The output buffer PANEL/LINE order, LEFT to RIGHT, TOP TO BOTTOM

**Short List of Methods:**

> void    About();                   // Dumps Version info to Serial

> void    Begin(char **Buffer, int pBufferSize, int pBufferLen, int pIsBufferProgMem); // Defines buffers 0=ram,1=flash**

> void    ClearOutput();             // Clears the output buffer

> void    DumpPanels();              // Dumps the output buffer contents in panel form to serial

> void    FillOutput();              // Fill output buffer with text

> void    Loop();                    // The main processing pump

> void    NewMessage();              // Called whenever the text message is changed, resets buffers

> void    Scroll();                  // Called to display & optionally scroll

> void    SetScrolling(short i);     // Called to set scrolling 0=off, 1=on