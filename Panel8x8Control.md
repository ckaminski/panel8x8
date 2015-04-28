#Panel8x8Control - Control Application for the 8x8 Panel Library.

# Introduction #

Control Application for the 8x8 Panel Library.


# Details #

**Example 6 - Serial Update must be loaded to the panels for any of the Panel8x8Support programs to work.  This is because the DotNet code communicates with the array using the serial interface.  This is the same interface you use to program the array, so note the channel you are using in the Arduino studio.  The Serial debugging window cannot be active while using the Panel8x8Support apps (that's a port sharing violation in Windows!)  Also, please be sure to set the port to 9600 baud, that's the current setting per the Panel8x8Serial object code.**

This program provides a means for updating text and framedelay.

Simply use an FTDI compatible cable such as the USB Bub or FTDI Cable.

The User, Password, enable block is used to program the app to read and display the most recent twitter posting on a user's twitter page.

Minimum version 1.06 & Example 6 are required.