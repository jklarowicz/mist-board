# Gamepad/Joystick keyboard shortcuts #

Pressing certain button combinations with a USB joystick or gamepad will send specific keyboard keys to a core. This is useful for certain games that require a key press to continue.

The keyboard commands are made from the _virtual gamepad_ [as defined in this page](http://code.google.com/p/mist-board/wiki/USBJoystickMapping). You can use mist.ini to change how hardware buttons map to the virtual gamepad, allowing to change which buttons trigger the below.

## Command mappings (START) ##

  * **START + A:** press Enter key
  * **START + B:** press Space bar
  * **START + L:** press ESC key
  * **START + R:** press F1 key
  * **START + SELECT:** press F12 (opens OSD in most cores)

## Mouse emulation (SELECT) ##

Keep **SELECT** pushed to emulate a mouse:
  * **directions**: Move cursor
  * **L**: Left click
  * **R**: Right click


# OSD joystick control #

When keyboard shortcuts are active, a controller can also be used to control the OSD:

  * **A:** choose / enter menu
  * **B:** cancel / return to previous menu
  * **Up/Down/Left/Right:** move around menu
  * **SELECT + Up/Down:** Pageup/Pagedown
  * **L + Up/Down:** Pageup/Pagedown
  * **R + Up/Down:** Pageup/Pagedown

# Disabling shortcuts #

To disable the above joystick mappings, set the following in mist.ini:
```
joystick_disable_shortcuts=1
```