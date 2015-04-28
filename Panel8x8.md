#Panel8x8 Object

# Introduction #

This is the object provided by the Panel8x8 Library

# Details #

Methods:
| About() | Displays current library version to serial |
|:--------|:-------------------------------------------|
| AddChar() | Adds one character to the panel output |
| Begin(buffer,max,len,isRom=0/1) | Initializes buffers |
| ClearOutput() | Erases the panel output |
| DumpPanels() | Debug routine to display panel output as text to serial port |
| FillOupput() | Makes calls to AddChar() to fill the panel output |
| GetByte(idx) | Gets a byte by index from the input buffer |
| getNextLetter(l) | Gets the next letter from the input buffer for ouput |
| LoadAnimation() | Loads next animation frame to panel output |
| Loop() | Called to pump the panel display |
| NewMessage() | Called whenever input buffer changes, resets buffer pointers |
| Scroll() | Called to output and optionally scroll the panel output |
| SetScrolling(i) | Called to turn scrolling on or off |
| WriteByte(idx) | Writes a byte by index to the input buffer |

Properties:
| bIsScrolling | Whether or not the panels are allowed to scroll |
|:-------------|:------------------------------------------------|
| frameDelay | The delay between panel refreshes |
| iBufferLen | Current length of the input buffer |
| iBufferSize | Max number of bytes in the input buffer |
| idxNext | High water mark, compared to idxScroll to decide when to add characters |
| idxMsg | Where are we at in the current input text buffer |
| idxScroll | Bit index into the output panels for next character to be added |
| iFrames | Number of animation frames |
| isBufferProgMem | Binary, Is this input buffer ram (0) or rom (1) |
| iScroll`[`Panels`]``[`8`]` | The panel output matrix |
| iPanels | Current number of panels to draw |
| PanelMode | 1=Text, 2=Animating, 3=Live Streaming |
| `*`ramBuffer | The input buffer |

Sample Code:
```
#include <Panel8x8.h>
Panel8x8 panel;
char *buffer[512]="Testing 1, 2, 3!  ";
void setup(){panel.Begin(buffer,512,strlen(buffer),0);}
void loop(){panel.Loop();}
```