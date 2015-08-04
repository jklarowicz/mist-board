# Introduction #

This page has operating instructions for the Atari 800 core.

# Links #
  * [Core binaries (use latest date)](http://www.scrameta.net/autobuild/)
  * [Official core manual](http://www.scrameta.net/Atari%20800%20FPGA%20Manual.pdf)
  * [Source code](http://www.scrameta.net/atarixlfpga_svn/trunk/)
  * [Author's home page](http://www.scrameta.net/)
  * [Thread at AtariAge](http://atariage.com/forums/topic/213827-potential-new-hardware/)

# Installation #

_For a more complete guide please refer to the official manual linked above._

After following the binary link above, go into the latest folder and find `atari800.rbf` located under `/mist/build_NTSC_VGA/out/` .
Copy the file to the root of an SD card, and if you will only use the SD card for this core, then also rename the file to `core.rbf`.


Create the following sub-folders in the SD card:
  * `/atari800/`
  * `/atari800/rom/`
  * `/atari800/user/`

Copy an image of the Atari800 ROMs into the `/atari800/rom/` folder.
You will need three files: `ATARIBAS.ROM`, `ATARIOSB.ROM`, and `ATARIXL.ROM`.

Copy games into the `/atari800/user/` folder. Supported file formats are CAR, ATR, XFD, XEX.

If everything is setup correctly you should see this screen at startup:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/atari800_start.jpg' title='startup' width='320px' />



---


# Controls #

For a full keyboard mapping reference, please refer to the official core manual.

  * F5: Help
  * F6: Start
  * F7: Select
  * F8: Option (see note below)
  * F9: Reset
  * F10: Cold start
  * F11: Load new disk or cartridge
  * F12: Enter System menu
  * Pause: Break
  * Delete: Freezer (if installed, see official manual)
  * Left Alt: Toggle scanlines
  * Right Alt: Atari key

You can use any gamepad / joystick for games, although some games will require the use of an analog controller. These are only supported via USB, and you can use an adapter to connect a real 2600/5200 analog controller.


---


# System Menu #

Press F12 to enter the OSD Menu.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/atari800_menu1.jpg' title='menu1' width='320px' />

In this menu you need to move around with the keyboard arrow keys, and select with Enter.

  * **Turbo**: accelerate the core (default is 1X)
  * **Ram**: Avaiable RAM, can choose different extension options
  * **Rom**: Name of the ROM being used.
  * **Drive 1-4**: Load disk from `/atari800/user/`
  * **Cart**: Choose a cart to load from `/atari800/user/`

Turbo should be left at 1X for maximum compatibility (a higher value could cause image glitches in some games).

It is possible to change the Rom path through this menu, but not necessary.

You can press F11 instead of F12 to directly go into the Load Disk option.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/atari800_menu2.jpg' title='menu2' width='320px' />

**Note**: When selecting a game, keep **F8** press to load disabling the BASIC bios, this improves compatibility with games (this "quirk" is from the real machine, and happens when you try to run machine language games from BASIC).

Some games require using Start, which is F6.


---


# Gameplay videos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=84rXFigAzVg' target='_blank'><img src='http://img.youtube.com/vi/84rXFigAzVg/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=XZddCDiOpfw' target='_blank'><img src='http://img.youtube.com/vi/XZddCDiOpfw/0.jpg' width='425' height=344 /></a>




---
