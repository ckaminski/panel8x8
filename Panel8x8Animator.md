# Panel8x8Animator creates, uploads, and streams animations to a Panel8x8 Array.

# Introduction #

Panel8x8Animator is a DotNet 3.5 program used to create, upload, and stream animations to a Panel8x8 Array.

# Details #

**Example 6 - Serial Update must be loaded to the panels for any of the Panel8x8Support programs to work.  This is because the DotNet code communicates with the array using the serial interface.  This is the same interface you use to program the array, so note the channel you are using in the Arduino studio.  The Serial debugging window cannot be active while using the Panel8x8Support apps (that's a port sharing violation in Windows!)  Also, please be sure to set the port to 9600 baud, that's the current setting per the Panel8x8Serial object code.**

Allows the creation, upload, and streaming of full panel animations.

Sample animations are loaded to MyDocuments\Animations
Click Load and use the VCR buttons to navigate throught frames.

Use COMM to upload or stream animations to the board.

The program will refuse to upload animations if there is enough RAM space available or if a Program Memory buffer was chosen.  In this case you should stream animations to the board.

Streaming sends frames of data directly to the panel.  On successful completion, the next panel is sent.  The Animation is looped at the end.

Minimum version 1.06 & Example 6 are required.