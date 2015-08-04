# Overview #

This page has operating instructions for the C64 core.

# Links #
  * [Peter Wendrich's FPGA64](http://www.syntiac.com/fpga64.html)
  * [Core binaries (with Peter's permission)](http://code.google.com/p/mist-board/source/browse/trunk/bin/cores/fpga64)


# Installation #

Copy the `*`.rbf file at the root of the SD card.
You can rename the file to core.rbf if you want the MiST to load it automatically at startup.

The core defaults to PAL (50hz) video; to start on NTSC video (60hz) you can copy the configuration file available in the MiST Starter Pack.

# OSD Menu #

Press F12 to enter the OSD menu:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/c64osd1.jpg' title='OSD Menu - Page 1' width='320px' />

  * **Load `*`.PRG**: read from SD card into memory
  * **Video Standard**: switch between PAL (50hz) and NTSC (60hz) video mode.
  * **Joysticks**: some games require joysticks to be swapped.
  * **Reset**: restart the C64 core, e.g. to change to another game/program.


<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/c64osd2.jpg' title='OSD Menu - Page 2' width='320px' />

  * **Firmware & core**: allows to switch to another core or upgrade the MiST firmware
  * **Save settings**: save the current settins to the SD card for next startup

## Notes ##

  * PAL mode is 720x576p @50hz
  * NTSC mode is 720x475p @60hz.
  * After loading a .PRG file, type "RUN" then Enter to start.

The unusual NTSC resolution of this core might give trouble to some displays.

# Obtaining PRG files #

If you do not have .prg files, you can extract them from existing .D64 images by using a program called [DirMaster](http://style64.org/dirmaster)


# Diagnostic Programs #

  * [BoulderMark](http://csdb.dk/release/?id=100487)

<img src='http://i.imgur.com/ayjqToW.jpg' title='bouldermark1' width='240px' /> <img src='http://i.imgur.com/i1oJ28e.jpg' title='bouldermark2' width='240px' /> <img src='http://i.imgur.com/jRHpCfC.jpg' title='bouldermark_results' width='240px' />

Bouldermark was designed for the PAL machine (50hz) and scores 314 points in PAL mode, which matches the performance of real C64 hardware. Running the test with the NTSC option (60hz) gives a lower score which is equal to 314\*50/60.


---


# Gameplay videos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=9GDJRWBFZu0' target='_blank'><img src='http://img.youtube.com/vi/9GDJRWBFZu0/0.jpg' width='425' height=344 /></a>


---
