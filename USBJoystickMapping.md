# Overview #

The MiST supports several common USB joysticks and gamepads (mostly anything with standard HID support). These come in many shapes and their buttons aren't always conveniently allocated, so to standardize how joysticks are handled the MiST features a _virtual gamepad_ that the hardware translates to. You can choose to override the mapping through use of the mist.ini file.

This virtual gamepad is similar to a SNES/PS1 gamepad with these elements:
  * **Four directions** (right, left, down, up)
  * **A**, **B**, **Select**, and **Start** buttons
  * **X**, **Y**, **L**, and **R** buttons
  * **L2**, **`R2`**, **L3**, and **`R3`** buttons

These are arranged into an array of 16 values:

| right | left | down | up | `A` | `B` | `SELECT` | `START` | `X` | `Y` | `L` | `R` | `L2` | `R2` | `L3` | `R3` |
|:------|:-----|:-----|:---|:----|:----|:---------|:--------|:----|:----|:----|:----|:-----|:-----|:-----|:-----|

(technical note - least significant bit is on the left in this table, 0x01 = right)

At time of writing, the available cores will only use the first two sets of buttons (directions, two buttons, select, start), but the rest can be used for additional functionality by being bound to keyboard shortcuts (in particular X, L, and R), [as described here](http://code.google.com/p/mist-board/wiki/JoystickShortcuts).

# Default mapping #

By default all HID devices map to a gamepad with 4 directions and twelve buttons:

| **Hardware** | right | left | down | up | btn 1 | btn 2 | btn 3 | btn 4 | btn 5 | btn 6 | btn 7 | btn 8 | btn 9 | btn 10 | btn 11 | btn 12 |
|:-------------|:------|:-----|:-----|:---|:------|:------|:------|:------|:------|:------|:------|:------|:------|:-------|:-------|:-------|
| **MiST**     | right | left | down | up | `A`   | `B`   | `SELECT` | `START` | `X`   | `Y`   | `L`   | `R`   | `L2`  | `R2`   | `L3`   | `R3`   |
| **Hex**      | `0x01` | `0x02` | `0x04`  | `0x08` | `0x10` | `0x20` | `0x40` | `0x80` | `0x100` | `0x200` | `0x400` | `0x800` | `0x1000` | `0x2000` | `0x4000` | `0x8000` |

Custom mapping can be applied per button by configuring the corresponding value to be the hexadecimal sum of the numbers above. For example if one wanted to map "btn 7" to A + B, one would enter `0x08` + `0x10` = `0x18`. (if you translate the values to binary, you will notice there is one bit per button on a 16-bit array, and e.g. 0xFFFF would press all buttons and directions at once).



# mist.ini mapping #

The mapping can be overidden by entering a line like the below in mist.ini, in this example we map the iBuffalo SNES pad:
```
joystick_remap=0583,2060,1,2,4,8,10,20,20,8,400,800,40,80
```

The first two numbers, 0584 and 2060 are the VID and PID hex codes that the devices report. These can be seen by plugging the USB controller in Windows and looking at hardware properties.

The next four numbers are the mapping for the directional gamepad. These act like a digital gamepad ("POV hat"), overriding any analog joystick values if pressed. The mapping used in the example above is the default:

| right | left | down | up |
|:------|:-----|:-----|:---|
| `0x01` | `0x02` | `0x04`  | `0x08` |

After this are buttons (up to twelve) arranged in order that the devices reports them. The exact ordering can vary but it can be seen by plugging a USB device in Windows, looking at controller properties, and pressing buttons to see which number they correspond to.

In the mapping string from the example above we've used these values:

| **Hardware** | btn 1 | btn 2 | btn 3 | btn 4 | btn 5 | btn 6 | btn 7 | btn 8 |
|:-------------|:------|:------|:------|:------|:------|:------|:------|:------|
| **Hex**      | `0x10`  | `0x20` | `0x20` | `0x08` | `0x400` | `0x800` | `0x40` | `0x80` |
| **MiST**     | `A`   | `B`   | `B`   | `Up`  | `L`   | `R`   | `SELECT` | `START` |

This will result in the following mapping:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/gamepad_.jpg' title='OSD Menu' width='480px' />

This provides two ways to hold the game pad for B, A buttons, and maps one extra button to "Up" for use as a jump button on several Amiga/ST games. L and R are not used by cores, but they're used by the OSD to activate "Pageup" and "Pagedown" when pressed with up/down while going through file selection.

# Tutorial - creating your own mappings with Windows #

The mapping is very flexible so you can experiment to find your favorite setup per gamepad, even remapping directions to buttons (and vice-versa) if you wish to do so.

At the moment up to four sets of mappings are supported in the .ini (but more can be added if requested).

### Base Test of HID gamepad ###

The first step is to find out if your controller is at all recognized by the MiST. For this just plug it and try using it with a game, if directions and at least one button work you can proceed.

### VID / PID codes ###

The next step is to work out the hardware IDs that the MiST will use to apply the mapping (VID/PID).
For this you can plug the controller in Windows, then open the Device Manager and right click on the icon for the controller and select "Properties" (do not confuse it with "Game Controller settings"). Then go to the "Hardware" tab, select "HID-compliant game controller" then click the `Properties` button. In the windows that pops up select the "Details" tab and choose "Hardware IDs" in the drop down selection. You should have something like the below where you can read a VID and PID numbers:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/gamepad_windows_vid.jpg' title='OSD Menu' width='640px' />

These are used in the first part of the mapping. As an example let's assume we do not want to remap directions, so we'll keep the first set of mappings as the default. This string will map only the directions and disable all buttons:

```
joystick_remap=0583,2060,1,2,4,8
```

### USB Buttons ###

Finally the last step is to map hardware buttons to the MiST virtual joystick. After the VID, PID, and four directions, each entry on the mapping string directly maps to the button number as displayed by Windows.

Go back to the Device Manager but select "Game Controller settings" this time. This brings up a menu with all your connected controllers. Choose the right one and select "Properties" to view how Windows recognized the gamepad. In this window you can press a button and the corresponding number will light up.

In the example below we press the START button on the gamepad, and can see it maps to USB button number 8:

<img src='http://mist-board.googlecode.com/svn/wiki/img_docs/gamepad_windows_buttons.jpg' title='OSD Menu' width='640px' />

This means that in order to map the physical START button to the START of the virtual joystick we must apply mapping to the 8th USB button. We know (from table above) that virtual gamepad START mapping is `0x80`, so to assing this button we would use this string (assuming no other buttons are mapped):

```
joystick_remap=0583,2060,1,2,4,8,0,0,0,0,0,0,0,80
```

The string above will map the four directions, then skip 7 buttons, and assign the 'virtual' START button to the eight USB button. Subsequent buttons are ignored unless more values are added at the right:

| **Hardware** | right | left | down | up | btn 1 | btn 2 | btn 3 | btn 4 | btn 5 | btn 6 | btn 7 | btn 8 | btn 9 | btn 10 | btn 11 | btn 12 |
|:-------------|:------|:-----|:-----|:---|:------|:------|:------|:------|:------|:------|:------|:------|:------|:-------|:-------|:-------|
| **MiST**     | right | left | down | up |       |       |       |       |       |       |       | `START` |       |        |        |        |
| **Hex**      |`0x01` |`0x02`|`0x04`|`0x08` |       |       |       |       |       |       |       | `0x80` |       |        |        |        |

Using this method you can work out which USB button number corresponds to each physical button and map it to the desired MiST _virtual_ button. It is recommended that you at least map four: **A**, **B**, **SELECT**, and **START**:

```
joystick_remap=0583,2060,1,2,4,8,10,20,0,0,0,0,40,80
```

Which corresponds to:


| **Hardware** | right | left | down | up | btn 1 | btn 2 | btn 3 | btn 4 | btn 5 | btn 6 | btn 7 | btn 8 | btn 9 | btn 10 | btn 11 | btn 12 |
|:-------------|:------|:-----|:-----|:---|:------|:------|:------|:------|:------|:------|:------|:------|:------|:-------|:-------|:-------|
| **MiST**     | right | left | down | up | A     | B     |       |       |       |       | `SELECT` | `START` |       |        |        |        |
| **Hex**      |`0x01` |`0x02`|`0x04`|`0x08` | `0x10` | `0x20` |       |       |       |       | `0x40` | `0x80` |       |        |        |        |


### Combining buttons ###

A few keyboard shortcuts have been defined based on the virtual gamepad; out of these one of the most useful is START+SELECT to open the OSD. Let's assume you have a gamepad with many buttons and button 12 happens to be conveniently located to be used as a standalone OSD button.

To trigger the keyboard shortcut one needs to have both START and SELECT pressed. This means we need to assign both as mapping to button 12 to trigger it. This is done by summing the values of START and SELECT together, `0x40` + `0x80` = `0xC0`, and assigning the value to the 12th USB button:

```
joystick_remap=0583,2060,1,2,4,8,10,20,0,0,0,0,40,80,0,0,0,C0
```

Which is in our mapping table:

| **Hardware** | right | left | down | up | btn 1 | btn 2 | btn 3 | btn 4 | btn 5 | btn 6 | btn 7 | btn 8 | btn 9 | btn 10 | btn 11 | btn 12 |
|:-------------|:------|:-----|:-----|:---|:------|:------|:------|:------|:------|:------|:------|:------|:------|:-------|:-------|:-------|
| **MiST**     | right | left | down | up | A     | B     |       |       |       |       | `SELECT` | `START` |       |        |        | `SELECT + START`  |
| **Hex**      |`0x01` |`0x02`|`0x04`|`0x08` | `0x10` | `0x20` |       |       |       |       | `0x40` | `0x80` |       |        |        | `0xC0` |

Many other combinations are possible - giving you full flexibility on customizing how your HID-compatible controllers work with the MiST.