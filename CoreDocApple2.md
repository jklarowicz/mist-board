# Overview #

This page has operating instructions for the Apple II+ core.


# Links #
  * [Winfried's blog about the apple2 core for the MIST](http://ws0.org/tag/apple2/)
  * [Core binaries](http://code.google.com/p/mist-board/source/browse/trunk/bin/cores/appleii%2b)
  * [Source code repository](https://github.com/wsoltys/mist-cores/tree/master/apple2fpga)
  * [Homepage of the Apple2FPGA project](http://www1.cs.columbia.edu/~sedwards/apple2fpga/)


# Installation #

Copy the `*`.rbf file at the root of the SD card.
You can rename the file to core.rbf if you want the MiST to load it automatically at startup.

Disk images can be copied anywhere on the SD card and are selected via the OSD menu. They must be in NIB format to work (instead of e.g. DSK).
If you have many files you might want to store them into alphabetized sub-folders to access them more quickly.


---


# Controls #

MiST front panel buttons:
  1. (left) Reset MiST to default core
  1. (middle) Open OSD menu
  1. (right) Reset with current disk

# OSD Menu #

The core will start with a blank screen. Press F12 to enter the OSD menu:

  * **Load `*`.NIB**: Insert .NIB disk image in drive 1
  * **Load `*`.NIB** (second line): insert disk in drive 2
  * **Monitor Type** (Color/Monochrome): Select Monochrome for Green or Amber screen
  * **Monitor Mode**: Toggles between Color/Raw B&W mode (Color monitor) or Green/Amber (Monochrome monitor)
  * **Enable Scanlines**: turn it on to display scanlines like a CRT
  * **Joysticks**: normal/swapped

# Monitor Options #

Here is a comparison of the four video choices. Color monitor shows either Apple II colors (simulating NTSC composite, top left) or a raw B&W display (bottom left). On the right are the two monochrome modes (green on top, amber on bottom).

This image uses scanlines, the result is a little brighter if scanlines are switched off.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/apple2_monitors.jpg' title='screen mode comparison' width='640px' />


## Notes ##

  * Video mode is 720x481p at 60hz.



---


# Gameplay videos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=IAn9i7d4XV0' target='_blank'><img src='http://img.youtube.com/vi/IAn9i7d4XV0/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=PgcZwfU6IqU' target='_blank'><img src='http://img.youtube.com/vi/PgcZwfU6IqU/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=w3tSKhW22tc' target='_blank'><img src='http://img.youtube.com/vi/w3tSKhW22tc/0.jpg' width='425' height=344 /></a>


---

