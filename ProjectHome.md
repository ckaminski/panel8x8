![https://panel8x8.googlegroups.com/web/P8x8_00.jpg](https://panel8x8.googlegroups.com/web/P8x8_00.jpg)

Thanks everyone for stopping by!<br>
The access numbers are growing every day!<br>
Thanks for your interest in this project!<br>
- Dataman<br>
<br>
So, what does this library do?<br>
Quite simply put, this library provides an easy way to display text and graphics to the 8x8 Panels available from <a href='http://ModernDevice.Com'>http://ModernDevice.Com</a> . This library treats the panels as a simple display device.  Give it some command, text, or animation and it does the rest.  A plethora of examples and programs are included:<br>
<br>
<table><thead><th> # </th><th> Title </th><th> Description </th></thead><tbody>
<tr><td> 1 </td><td> Scroll Text RAM </td><td> Scrolls text stored in RAM. </td></tr>
<tr><td> 2 </td><td> Scroll Text FLASH </td><td> Scrolls text store in EPROM memory. </td></tr>
<tr><td> 3 </td><td> Animation FLASH </td><td> Runs animation from ERPROM memory. </td></tr>
<tr><td> 4 </td><td> Animation Test Pattern </td><td> Runs an animation generated on the fly </td></tr>
<tr><td> 5 </td><td> Game of Life </td><td> Plays Conways Game of Life </td></tr>
<tr><td> 6 </td><td> Serial Update </td><td> Accepts commands over serial, unlimited text or graphics! </td></tr>
<tr><td> 7 </td><td> Ethernet Update </td><td> Runs a mini web browser to update text on display </td></tr>
<tr><td> 8 </td><td> Wireless Update </td><td> Runs a mini web browser to update text wihtout wires! </td></tr>
<tr><td> 9 </td><td> SD Update </td><td> Streams animations off an SD Card </td></tr></tbody></table>

All programs require Example 6, Serial Update be loaded.<br>
<table><thead><th> Program </th><th> Function </th></thead><tbody>
<tr><td> Panel8x8Control </td><td> Send text and scroll rate commands to the array.  Also performs automatic twitter updates. </td></tr>
<tr><td> Panel8x8Animator </td><td> Allows for the creation and editing of animations.  May be streamed directly to the panel or loaded into ERPROM. </td></tr>
<tr><td> Panel8x8CharacterEditor </td><td> Simple program to allow editing of the character fonts used in Panel8x8. </td></tr></tbody></table>

<b>Published source code to utilties</b>
I thought I had lost the source code to the Panel8x8Utilities.<br>
I found it today, and posted to github at <a href='http://github.com/dataman/Panel8x8Support'>http://github.com/dataman/Panel8x8Support</a>
Visual Studio 2005 I think, happy coding.<br>
<br>
<b>Animator Tutorial Now Online</b>
Realized I forgot to post the Animator tuturial,<br>
It's now available here: <a href='http://panel8x8.googlecode.com/files/Panel8x8HowToAnimate.mp4'>http://panel8x8.googlecode.com/files/Panel8x8HowToAnimate.mp4</a>

<b>Discussion Group:</b><br>
I've set up a new discussion group to get some feedback...<br>
<img src='http://groups.google.com/intl/en/images/logos/groups_logo_sm.gif' /><br>
Visit the group: <a href='http://groups.google.com/group/panel8x8'>http://groups.google.com/group/panel8x8</a>

<b>Build information:</b><br>
Step by step build instructions can be found here:<br>
<a href='http://crjones.brinkster.net/Panel8x8'>http://crjones.brinkster.net/Panel8x8</a>

<b>Current Version:</b> 1.09 Bug Fixed<br>
<ul><li>Bug fixed, online, complete, and in the bag!<br>
<b>Version 1.08:</b> FEATURE COMPLETE!<br>
<ul><li>WOHOO!  WE'RE DONE!<br>
</li><li>SD Card Streaming, save files to SD card for nearly unlimited memory!<br>
<b>Version 1.07:</b> Ethernet, Wifi<br>
</li><li><a href='Ethernet_Update.md'>Ethernet_Update</a> via built in web server<br>
</li><li><a href='Wifi_Update.md'>Wifi_Update</a> via built in web server<br>
<b>Version 1.06:</b> Serial<br>
</li><li>Panel8x8Serial object that supports update over serial connection<br>
</li><li>Panel8x8Support Apps included!<br>
<ul><li>Panel8x8Control<br>
<ul><li>Update Text<br>
</li><li>Change FrameDelay (faster/slower)<br>
</li><li>Automatic Twitter Updates<br>
</li></ul></li><li>Panel8x8CharacterEditor<br>
<ul><li>Design characters for inclusion into Program Memory<br>
</li><li>Supports cut and paste in code format<br>
</li></ul></li><li>Panel8x8Animator<br>
<ul><li>Create, Load, Save<br>
</li><li>Playback simulator<br>
</li><li>Upload to Array if enough memory<br>
</li><li>Stream frame by frame if not enough memory<br>
</li></ul></li></ul></li><li>Step by Step build instructions (see link to the right)<br>
</li><li>Wiki updated with details on the <a href='Panel8x8.md'>Panel8x8</a> and Panel8x8Serial objects<br>
<b>Version 1.05:</b> Unix Compile<br>
</li><li>Removed Windows type compile path (sorry!)<br>
<b>Version 1.04:</b> Removed Overrides<br>
</li><li>Client side compile switches not working - removed<br>
<b>Version 1.03:</b> Initial Release<br>
</li><li>Initial Public Release - Wohoo!</li></ul></li></ul>

Code required to display scrolling text on one or more panels is now as simple as:<br>
<pre><code>#include &lt;Panel8x8.h&gt;<br>
Panel8x8 Panel;<br>
char buffer[512]={"This is a test, this is only a test."};<br>
void setup() { Panel.Begin(buffer,512,strlen(buffer),0);}<br>
void loop() { Panel.Loop(); }<br>
</code></pre>

The goal of this library is to simplify programming of the 8x8 Panel available from <a href='http://ModernDevice.Com'>http://ModernDevice.Com</a> while greatly adding to its flexibility.<br>
<br>
Goals:<br>
<br>
(Provided by Base Version)<br>
<ul><li>Provide and Panel8x8 class that can easily be added to sketches.<br>
</li><li>Support any number of panels.<br>
</li><li>Process Text or Graphics stored in Ram or Flash memory.</li></ul>

Implemented:<br>
<ul><li>Update via serial connection. (V1.06)<br>
</li><li>Update ethernet. (V1.07)<br>
</li><li>Update wireless. (V1.07)<br>
</li><li>Update vis SD Card. (V1.08)</li></ul>

