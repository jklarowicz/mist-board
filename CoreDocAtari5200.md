# Introduction #

This page has operating instructions for the Atari 5200 core.

# Links #
  * [Core binaries](http://www.scrameta.net/autobuild/)
  * [Official core manual](http://www.scrameta.net/Atari%20800%20FPGA%20Manual.pdf)
  * [Author's home page](http://www.scrameta.net/)
  * [5200 core thread at AtariAge](http://atariage.com/forums/topic/216991-5200-in-fpga/)

# Installation #

After following the binary link above, go into the latest folder and find `atari5200.rbf` located under `/mist_5200/build_NTSC_VGA/out/` .
Copy the file to the root of an SD card, and if you will only use the SD card for this core, then also rename the file to `core.rbf`.


Create the following sub-folders in the SD card (note the missing i):
  * `/atar5200/`
  * `/atar5200/rom/`
  * `/atar5200/user/`

Copy an image of the Atari5200 ROM into the `/atar5200/rom/` folder, renaming it to **5200.rom** so the core will find it.

Copy games into the `/atar5200/user/` folder.


---


# Controls #

  * F1: Start
  * F2: Pause
  * F3: Reset
  * F10: Cold reset
  * F11: Load new ROM
  * F12: Enter OSD menu

You can use any gamepad / joystick for games, although some games will require the use of an analog controller. These are only supported via USB, and you can use an adapter to connect a real 5200 controller.

With a regular USB controller, you can access the keypad functions of the original controller via keyboard (US layout):

|F1|F2|F3|
|:-|:-|:-|
|1 |2 |3 |
|Q |W |E |
|A |S |D |
|Z |X |C |

The above corresponds to this in the Atari pad:

|Start|Pause|Reset|
|:----|:----|:----|
|1    |2    |3    |
|3    |4    |5    |
|6    |7    |8    |
|`*`  |0    |#    |

# OSD Menu #

On startup you will see an Atari logo with no ROM loaded:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/a5200_start.jpg' title='Atari 5200 start' width='320px' />

Press F12 to enter the OSD Menu.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/a5200_settings.jpg' title='Atari5200 menu' width='320px' />

In this menu you need to move around with the keyboard arrow keys, and select with Enter.

  * **Turbo**: accelerate the core (default is 1X)
  * **Ram**: Avaiable RAM, stays at 16K
  * **Rom**: Name of the ROM being used.
  * **Cart**: Choose a cart to load from `/atar5200/user/`

It is possible to change the Rom path through this menu, but not necessary.

You can press F11 instead of F12 to directly go into the **Cart** option.

When selecting a cart, the core may not recognize the cart type so it may ask you to choose what cart type to load.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/a5200_cart_type.jpg' title='mapper supprot' width='320px' />

If you don't know which type it is, select one and see if the game loads.
If not, press F12 then load the ROM again as the other cart type.

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/a5200_splash.jpg' title='mapper supprot' width='320px' />

If the ROM loads, you can start the game with F1.


---


# Gameplay videos #

<a href='http://www.youtube.com/watch?feature=player_embedded&v=ys-9ZJnkg4E' target='_blank'><img src='http://img.youtube.com/vi/ys-9ZJnkg4E/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=VAWqKU22eO0' target='_blank'><img src='http://img.youtube.com/vi/VAWqKU22eO0/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=yTKkwX2e39A' target='_blank'><img src='http://img.youtube.com/vi/yTKkwX2e39A/0.jpg' width='425' height=344 /></a>


---
