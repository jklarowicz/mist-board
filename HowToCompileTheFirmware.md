# Prerequisites #

The firmware is written in C. Thus a matching C compiler is needed. The current firmware setup expects a matching version of the gnu compiler collection (GCC) to be installed.



## Installing GCC on Linux ##

Installation is described in [this blog posting](http://retroramblings.net/?p=315). A [shell script](http://mist-board.googlecode.com/svn/trunk/tools/install_arm-none-eabi-gcc.sh) is available to automate the setup.

## Installing GCC on Windows ##

Refer to this page: [How to compile the firmware under Windows](http://ws0.org/compiling-the-minimig-core-for-the-mist-fpga-board-on-windows/)


# Compiling the source code #

The firmware source code is available from the [MIST svn repository](http://code.google.com/p/mist-board/source/checkout).

Once the compiler is installed a simple `make` in the firmware subdirectory will build the latest firmware.


# Installing the firmware #

Three files are generated during compilation:

  * **firmware.bin** is the raw binary of the firmware. This can be uploaded to the MIST board using special flashers
  * **firmware.hex** is the same firmware in intel hex format as required by some uploaders
  * **firmware.upg** is the same firmware in a format suited for self-update via the on-screen-display (OSD)

For more details on firmware installation read HowToInstallTheFirmware