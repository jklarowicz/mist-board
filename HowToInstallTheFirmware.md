# Firmware files #

The firmware comes in three formats:

  * **firmware.bin** is the raw binary of the firmware. This can be uploaded to the MIST board using special flashers
  * **firmware.hex** is the same firmware in intel hex format as required by some uploaders
  * **firmware.upg** is the same firmware in a format suited for self-update via the on-screen-display (OSD)

These are required for the various ways to update the firmware. Three methods to do so exist:

  * Update via OSD: This is the easiest way and is recommanded. But this requires a working firmware to be already present
  * Update via Sam-BA: This requires a micro USB cable and is a little bit more tricky, but it even works if there's no working firmware present. This can thud be used for emergency flashing e.g. after an unsuccessful flash attempt.
  * Update via JTAG: This is the fastest approach but needs a special jtag interface. This is mainly used during development. But this can also be used for emergency flashing.

# Can i brick my MIST with this? #

No, with a flash update you cannot bring the MIST into a state where it cannot be flashed with a working firmware again. If you broke the firmware (by e.g. unplugging the board while flashing it) you can always use the Sam-Ba approach. No further hardware (besides a USB cable) is required for that.

# Updating the IO controller using the OSD #

The easiest way to update the IO controller is via the OSD menu of the Minimig or Atari/MIST core. This requires a working Minimig setup. In order to update via the OSD the following steps are required:

  1. Place the _firmware.upd_ on the SD card
  1. Boot into Minimig or Atari MIST
  1. Open the OSD (F12)
    * On the Minimig go into the Misc menu (press right key two times) and select "Firmware"
    * On the Atari/MIST select the Firmware & Core submenu
  1. Make sure the Version numbers displayed are the ones you want to flash
  1. Press _Update_ and select _Yes_
  1. The update will take about 5 seconds
  1. The new firmware will reboot automatically

# Updating the IO controller via SAM-BA under Windows #

Alternally the SAM.BA self programming capabilities of the AT91SAM7 based IO controller can be used. This does not require a working Minimig setup and can even be used to flash an IO controller with broken firmware after e.g. a failed update attempt or the like.

The following steps are necessary to update the MIST firmware under Windows:

  1. Install [Atmel SAM-BA for Windows](http://www.atmel.com/tools/ATMELSAM-BAIN-SYSTEMPROGRAMMER.aspx) on your PC
  1. Switch the board off and remove the SD card
  1. Close the JP1 jumper
    * on early dev boards: next to the three push buttons
    * on the series boards: next to the Atmel ARM controller
    * be careful not to confuse it with switch DIP 1 (which will have no effect)
    * on most boards JP1 is not wired - it needs to be bridged with a wire
  1. Switch the board on, wait 10 seconds and switch it off again. The SAM-BA boot loader is now installed
  1. Remove the jumper and connect the board to the PC using a USB cable
    * on early dev boards: use a normal cable connected to the square USB plug next to the three push buttons
    * on the series boards: use a micro usb cable connected to the micro usb power input (the PC will then also power the board)
  1. Power the board on. The PC should recognize the board and install install a COM port for it (it will display the COM port number)
  1. Start SAM.BA on the PC. Select the COM device and set board type to _at91sam7s256-ek_ as depicted below

![http://mist-board.googlecode.com/svn/wiki/mist_samba1.jpg](http://mist-board.googlecode.com/svn/wiki/mist_samba1.jpg)

  1. Select _Connect_
  1. In the SAM-BA main screen under Scripts select _Erase_ _all_ _flash_ and hit the _Execute_ button

![http://mist-board.googlecode.com/svn/wiki/mist_samba2.jpg](http://mist-board.googlecode.com/svn/wiki/mist_samba2.jpg)

  1. Select _yes_ when being asked if you want to unlock the flash regions
  1. Select the MIST firmware file _firmware.bin_ under _Send_ _File_ _Name_ and hit the _Send_ _File_ button
  1. The new firmware will now be flashed
  1. Say _No_ when being asked whether you want lock the involved flash regions
  1. Power the board off, disconnect the USB cable, insert the SD card
  1. Power the board on. The new firmware should load.

# Updating the IO controller via SAM-BA under Linux #

Some people have problems to get the Linux version of SAM-BA to work. Instead Sam\_I\_Am under Linux works fine. The firmware source archive comes with a matching Makefile entry. Install the SAM-BA boot loader as explained above in the Windows section. Then just type make flash\_sam to flash the new firmware. The installation of Sam\_I\_Am on a recent Ubuntu machine required some moving around of files which i don't exactly remember. If in doubt use the windows installer as explained above.

# Updating the IO controller via JTAG #

Another way to flash the IO controller is via an ARM JTAG cable connected to the 20 pin JTAG header. You need an ARM JTAG cable and the apropriate software. The Makefile in the firmware source code comes with a flash target, so a simple
`make flash` will use the ARM JTAG interface to flash the IO controller. No manual interaction is required besides connecting the JTAG cable.

This is primarily intended for developers or for bulk flashing several devices.

Two types of arm jtag adapters have so far been tested. The [Olimex arm-usb-tiny-h](https://www.olimex.com/Products/ARM/JTAG/ARM-USB-TINY-H/) and the [busblaster](http://dangerousprototypes.com/docs/Bus_Blaster), both depicted below.

![http://mist-board.googlecode.com/svn/wiki/arm_jtag.jpg](http://mist-board.googlecode.com/svn/wiki/arm_jtag.jpg)

The arm-usb-tiny-h (in the grey db25 case) worked out of the box. The busblaster (the red pcb in the front) needed some tweaking as explained in the [dangerous prototypes forum](http://dangerousprototypes.com/forum/viewtopic.php?f=37&t=5598). Once successfully setup both devices perform equally well. The busblaster is a little cheaper but doesn't come with a case and without the 20 pin ribbon cable required to connect to the MIST.

The command to flash the firmware from **firmware.bin** via busblaster under Linux is e.g.:

```
openocd -f interface/busblaster.cfg -f target/at91sam7sx.cfg --command "adapter_khz 10000; init; reset init;  flash protect 0 0 7 off; sleep 1; arm7_9 fast_memory_access enable; flash write_bank 0 firmware.bin 0x0; resume; shutdown"
```