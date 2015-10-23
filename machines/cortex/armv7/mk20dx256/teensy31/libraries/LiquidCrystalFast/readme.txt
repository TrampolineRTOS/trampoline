LiquidCrystalFast Arduino Library
=================================

LiquidCrystalFast is an improved version of the Arduino LiquidCrystal
library.  The primary improvements are increased speed when the RW pin
is connected, and support for 40x4 displays.

LiquidCrystalFast History
-------------------------

In early-2010, John Raines rewrote the LiquidCrystal library, adding
several features, fixing problems, and greatly improving its speed.
The final version of John's excellent work is at:

http://code.google.com/p/liquidcrystal440/

John prepared a version for inclusion in Arduino 0019, with certain
features removed as requested by the Arduino developers.  However,
the Arduino project never adopted John's code.

In mid-2011, Paul Stoffregen merged some of John's versions of the
library and renamed it "LiquidCrystalFast", so it can be used on
Arduino without removing LiquidCrystal.

Speed Increase (with RW pin)
----------------------------

Using the example in File > Examples > LiquidCrystalFast > Benchmark
on a Teensy 2.0 with Arduino 0022 and Teensyduino 0.95 running on
a 16x2 LCD:

LiquidCrystalFast:  89 milliseconds.
LiquidCrystal:     354 milliseconds.


John Raines's Original Readme
=============================

This version of LiquidCrystal supports the API of LiquidCrystal in
Arduino 17 fully but does not actually ever use 8 data pins. This
change makes the code smaller, saving flash RAM and also less complex,
making it easier to read.

40x4 LCDs
---------

I added support for an LCD of 4 LInes and 40 characters. I think that
if 24x4, 32x4 LCDs exist, they would also work with the software as I
have modiﬁed it although I have not had the opportunity to test that.
The 40x4 LCD (and any HD44780 based LCD with between 81 and 160
characters) will have 2 enable lines.  To use an LCD with 4 lines and
40 columns you would declare your LiquidCrystal object as:

LiquidCrystal lcd(RS,RW,Enable1,Enable2, data3,data2,data1,data0);

At this time I donʼt support 8 data lines. (You can pass 255 as the
RW item, ground RW and save an Arduino pin.)  Then in the setup
function you would call:

lcd.begin(40,4);

Linewrap
--------

When you declare the dimensions of the LCD in your begin call, the
LiquidCrystal library remembers how long the lines are. Now when it
reaches the end of line 1, text wraps onto line 2 (not line 3 as
previously).

println
-------

Although print has worked properly in the past, println has not.  Now
the ʻ\rʼ and ʻ\nʼ characters are not sent to the screen as though they
were visible characters and the ʻ\rʼ resets the character position to
the top of the next line.

16x4 LCDs
---------

The begin statement also correctly positions text at the beginning of
the line on 16x4 (and 40x4) LCDs, which were not correctly handled
before.

setCursor
---------

In the past setCursor selected a location in the HD44780ʼs RAM not
actually a screen location. If you use any of the commands that shift
the display left or right with the previous routines, then setCursor
and print, text appears in an unexpected location on the screen.  With
the new software, if you call either scrollDisplayLeft() or
scrollDisplayRight(), the LiquidCrystal package keeps track of the
relationship between RAM and the LCD so that setCursor coordinates are
pegged to a speciﬁc spot on the screen, rather than a spot in RAM.
The sotware does not handle autoScroll, however.  Call home() after
autoScroll to restore the expected relationship between setCursor and
the LCD screen.

Testing the LCD Busy Flag
-------------------------
Previous versions of LiquidCrystal always used timed delays on the
Arduino side of the interface to give the LCD module enough time to
complete its operation.  This version still does that if you tie the
RW pin to ground and do not tell LiquidCrystal what that pin number
is.  If you do specify RW now, however, the software will poll the
busy ﬂag on the LCD module.  Arduino operations may thus overlap LCD
operations and potentially things may go a little faster.

Syntactic Sugar
---------------
#include <Streaming.h>
from http://arduiniana.org/2009/04/new-streaming-library/

Then you can combine that with an overloading of the () operator in
this code.  This lets you specify screen location and chain print
commands together by writing:

lcd(column,line)<<“a=”<<a;

Streaming.h is so efﬁcient you may actually save a few bytes of memory!

Speed testing
-------------

All of the interface modes go faster than the eye can follow.  This
version of the software is even slower than the previous version when
using timed delays.  I found that my LCD (Axman) needed an even longer
delay than before.  In the interests of making the code foolproof, I
lengthened the delays to make that LCD work.  However Paul Stoffregen
has signiﬁcantly speeded up the code when testing the busy ﬂag and
so those options run signiﬁcantly faster than before.  I compared the
speeds of the different interfaces--writing 80 characters to the
screen then 80 blanks and looping through that 20 times. The results
on a Mega are:

Axman 4 data pins no RW  1417 milliseconds  |  nonAxman 1417
Axman 4 data pins + RW    565 milliseconds  |  nonAxman 468
Axman 4 pins + user busy  369 milliseconds  |  nonAxman 316

I also have a Teensy++2.0 board. One of the interesting things about
that board is that the software that comes with it includes
considerable optimization of digitalRead, digitalWrite etc.  The board
runs at 16 megaHz, just like the Mega, but speeding up those commands
results in an impressive change in the benchmarks:

Axman 4 data pins no RW  1276 milliseconds  |  nonAxman 1276
Axman 4 data pins + RW    330 milliseconds  |  nonAxman 222
Axman 4 pins + user busy  241 milliseconds  |  nonAxman 190


Crazy 8 Addressing
------------------

16x1 LCDs often have an unusual address layout; these modules often
have two 8 character halves and work best with this software if you
declare them as:

lcd.begin(8,2);

If you do that, then you can print(“abcdefghilklmno”); and have all
the characters appear as you would like across the screen.  If you use
any of the scrolling commands, the bizarre addressing of these modules
will manifest itself. For details follow the _LCD Addressing_ link at
web.alfredstate.edu/weimandn

User callback busy test
-----------------------

Get LiquidCrystal running without this ﬁrst; setting up this
complicated option is error-prone and this should be left for last,
if implemented at all.  (the remainder of this section was removed)

Special note: LiquidCrystalFast does not have the user callback
feature.  For John's original code with user callback, please visit:

http://code.google.com/p/liquidcrystal440/

Disadvantages
-------------

The only real disadvantage I can see to the changes I have made is the
possibility that someone with a little 16x2 LCD is using the
scrollDisplayLeft() or scrollDisplayRight() instructions to move data
across the screen, but wants to write the data 40 characters at a time
with a print statement. This version really does not let the user
write data to the HD44780 DDRAM which is not visible. To accomplish a
scrolling display with 40 characters per line, you would now need to
write 16 characters, scroll the display, write a little more and so on.
There are going to be some incompatibilities between code that assumed
that line 1 wrapped onto line 3, etc.

Directions for the future
-------------------------
Paul Stoffregen suggested making the internal function send() public
rather than private so that classes that inherit from LiquidCrystal
can provide an alternate function, presumably hard coding pins and
getting still more speed. I made all of the ʻprivateʼ functions and
instance variables in LiquidCrystal ʻprotectedʼ. I think this allows
the same functionality, but have not yet tested this.

Bug
---

The one bug I am aware of is that autoscroll() on a 40x4 LCD only
scrolls 2 lines despite my best efforts.

Thanks
------

Certainly my efforts would not have been possible without the help and
prior efforts of David Mellis, Limor Friede, and Donald Weiman.  Don
was particularly patient in guiding me through the idiosyncracies of
the HD44780 based LCDs and especially in supplying an example of how
the busy ﬂag could be tested.  Paul Stoffregen contributed signiﬁcant
optimization of the code to make it faster.


