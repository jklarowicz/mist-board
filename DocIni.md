# Using mist.ini #

The MiST firmware has a few configuration options available, which can be set by adding  a "mist.ini" file to the root of the SD card.

Overall the file should contain a "mist" tag at the top:

```
[mist]
scandoubler_disable=0
mouse_boot_mode=0
joystick_ignore_hat=0
key_remap=04,05
key_remap=05,04
```

Comments can be added after each setting by using ; e.g.:

```
[mist]
scandoubler_disable=0 ; leave at 0 if not sure
...
```
# Description #

## scandoubler\_disable ##

If set to 1, some cores will disable their scandoubler to produce a 15khz video signal. This works better for upscalers and arcade displays. Also if you want to use a VGA-to-SCART cable with MiST, you need to set this option to 1.

Support is core specific; currently it is used by the ST, Amiga, Colecovision, Vic20 and Astrocade cores. All other cores will ignore the setting.

## mouse\_boot\_mode ##

Set to 1 to revert back to an old mouse handler which may solve compatibility issues with some mice (the default handler is much more compatible with keyboard/mouse wireless devices, though).

## joystick\_ignore\_hat ##

If set to 1, the firmware will revert to old behavior of using analog axes instead of the digital direction pad, which is the default behaviour for newer firmwares (since firmware\_150524).

## key\_remap ##

This allows you to remap USB HID keycodes reported to the cores. For example, if you want to exchange the keys 'a' and 'b' on your keyboard you'd want to have the USB HID keycodes 04 (the USB Usage ID of the key labeled 'a') and 05
to be exchanged the mist.ini would look like:

```
[mist]
key_remap=04,05
key_remap=05,04
```

This makes key 04 to be reported as key 05 and vice versa.