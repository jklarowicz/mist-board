# Introduction #

This page has operating instructions for the Acorn Archimedes **BETA** core by Stephen Leary.

**CURRENTLY THIS CORE IS IN BETA STATUS**

  1. Basic internals are implemented.
  1. Basic Floppy disk support
  1. Sound support added but may not work in all situations.
  1. The core emulates a 4Mb A3000 type machine with an ARM2a with caches disabled for now (has an A3010 style joystick interface).
  1. Core runs at ~91% of an ARM2 @ 8Mhz when using VGA Modes.
  1. Some games now run. Expect issues.

If someone has an MMC/SD card driver/podule then please mention it in the forums so it can be include it in the core.

# Links #

  * [Core binaries](http://code.google.com/p/mist-board/source/browse/trunk/bin/cores/archimedes/)
  * Source code (TBA)
  * [The Amber CPU core](http://opencores.org/project,amber)

# Installation #

Make sure to upgrade to the latest MiST firmware first.

Copy the Archimedes core into a root folder of the SD card. To make the MiST start with this core, rename it to `core.rbf`.

Copy a version of a RiscOS ROM into the root folder, renaming it to `riscos.rom`.

# Floppy disk images #

The current version supports two floppy drives. Floppy disk images ADF format and of exactly 819200 bytes in size are currently required. This is the most common format for the Acorn Archimedes.

Images named `floppy0.adf` and `floppy1.adf` are auto-inserted into the floppy disk drives on startup. Other images can be selected via the on-screen-display (OSD) which can be opened using the **Print Screen** key.


---


# OSD Menu #

If the ROM is recognized the core should boot into Risc OS.
Press **Print Screen** to open the OSD menu.

  * Floppy 0: Choose the floppy disk images to use for floppy 0
  * Floppy 1: Choose the floppy disk images to use for floppy 1
  * OS ROM: Choose the RISCOS rom to use
  * Firmware & Core: Change MiST core or upgrade firmware
  * Save config: Save current config for next boot

You can move to other pages of settings by pressing the right arrow key:

## Notes ##

  * For best results it's best to use this as the startup core.
  * If the core does not start try resetting the MiST (first button next to the SD card slot)
  * Only RISCOS 3 supports VGA.
  * Older RISCOS versions will need a VGA to SCART cable at present (future versions may have a scandoubler).

## License notes ##

This core uses the Amber CPU core from OpenCores which is LGPL.
The core itself is dual licensed LGPL/BSD.


---


## Desktop videos ##

<a href='http://www.youtube.com/watch?feature=player_embedded&v=h0TMT6Tp068' target='_blank'><img src='http://img.youtube.com/vi/h0TMT6Tp068/0.jpg' width='425' height=344 /></a>
<a href='http://www.youtube.com/watch?feature=player_embedded&v=YG_RhA6UBnk' target='_blank'><img src='http://img.youtube.com/vi/YG_RhA6UBnk/0.jpg' width='425' height=344 /></a>