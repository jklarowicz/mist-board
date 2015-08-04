# Introduction #

This page has operating instructions for the ZX Spectrum core.

# Links #

  * [ZX Spectrum on FPGA homepage](http://www.mike-stirling.com/retro-fpga/zx-spectrum-on-an-fpga/)
  * [Core binaries](http://code.google.com/p/mist-board/source/browse/trunk/bin/cores/spectrum)
  * [Info on the CSW1 file format](http://ramsoft.bbk.org.omegahg.com/csw.html#CSW1FORMAT)
  * [ESXDOS Homepage](http://www.esxdos.org/)

# Installation #

Copy the `*`.rbf file at the root of the SD card.
You can rename the file to core.rbf if you want the MiST to load it automatically at startup.

ROMs (.csw) can be copied anywhere on the SD card and are selected via the OSD menu.
If you have many files you might want to store them into alphabetized sub-folders to access them more quickly.

## Using DIVMMC/ESXDOS ##

_DivMMC supports loading .TAP, .Z80, and .SNA files_

The DIVMMC/[ESXDOS](http://www.esxdos.org/) combo provides easy and fast access to spectrum games stored on SD card. With release [r877](https://code.google.com/p/mist-board/source/detail?r=877) the zxmmc has been replaced by a DIVMMC implementation in the spectrum core.

In order to enable the DIVMMC on your MiST simply put the file `ESXMMC.BIN` from the [`esxdos085.zip`](http://www.esxdos.org/files/esxdos085.zip) onto the SD card and rename it to `spectrum.rom`. Follow the instructions in the ESXDOS  archive and also copy the entire `BIN` and `SYS` directories onto your SD card and boot your MIST with that.

On boot the SD card will immediately be detected. You can open the ESXDOS menu at any time using either the NMI entry from the MiST OSD, by pressing the fourth button on your USB gamepad (of course only if the gamepad has at least four buttons) or by pressing F11.

With ESXDOS in place CSW uploads doesn't work anymore. Remove the `spectrum.rom` file again if you need CSW upload.

## Converting CSW1 files ##

_Note: CSW loading is only supported via the OSD menu, and not the DivMMC interface_

  * The [TZX2WAV utility](https://code.google.com/p/mist-board/source/browse/#svn%2Ftrunk%2Ftools%2Ftzx2wav) can convert TZX files into CSW.
  * To convert TAP files into TZW you might need to use older utilities.

Some older utilities no longer work in the latest version of Windows, but you can use Dosbox to run them.


---


# OSD Menu #

The core will start with a blank screen. Press F12 to enter the OSD menu:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/zx_speccy_osd1.jpg' title='OSD Menu - Page 1' width='320px' />

  * **Load `*`.CSW**: load a CSW tape image from the SD card
  * **Reset**: restart the ZX spectrum core

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/zx_speccy_osd2.jpg' title='OSD Menu - Page 1' width='320px' />

The second page contains some general options:
  * **Firmware & core**: allows to switch to another core or upgrade the MiST firmware
  * **Save settings**: save the current settings to the SD card for next startup

In the rom selection screen, you can select a CSW with Enter.

## Notes ##

  * Video mode is 720x572p at 50hz.


---


# Gameplay videos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=1NdAtpZnerE' target='_blank'><img src='http://img.youtube.com/vi/1NdAtpZnerE/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=-noxm7VzhfM' target='_blank'><img src='http://img.youtube.com/vi/-noxm7VzhfM/0.jpg' width='425' height=344 /></a>


---


# Demos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=WV0I8n1uMTo' target='_blank'><img src='http://img.youtube.com/vi/WV0I8n1uMTo/0.jpg' width='425' height=344 /></a>