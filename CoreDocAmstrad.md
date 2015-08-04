# Introduction #

Welcome to Amstrad core for MiST-board.

This is a deployment of FPGAmstrad into MiST-board.

[Core Developer's Notes](CoreDocAmstradNotes.md)

# Installation #

You need :
  * MiST-board platform, with firmware updated [>= firmware\_150315\_r841.upg](https://code.google.com/p/mist-board/source/browse/trunk/bin/firmware/)
  * [amstrad core rbf file](http://code.google.com/p/mist-board/source/browse/#svn/trunk/bin/cores/amstrad)
  * [amstrad ROMs and a dsk](http://code.google.com/p/mist-board/source/browse/#svn/trunk/bin/cores/amstrad/OS6128_BASIC1-1_AMSDOS_MAXAM) (OS6128.ROM, BASIC1-1.e00, AMSDOS.e07, AST-Equinox.dsk)



Using the OSD menu (F12), do select a dsk.
You can enter **cat** instruction to list dsk content. Executables are files in **.bas** or **.bin**.
You can then enter **run"file.bas** to run the choosen executable.

## Note about installation : known bug ##
If you feel like if some files are corrupted after a hard-reboot, do defrag your sdcard (I have to fix that in next versions)

Robust test you can do also in release 003 : copy files from SD to hard disk, quick format, copy back files from hard disk to SD. If succeed, it's a file fragment problem so fixable in next versions... if not please contact me.

# Controls #

  * _F1_ _F2_ _F3_ at the top are mapped correctly.
  * _left_ _shift_ is the true shift key. _Right_ _shift_ one is used just to map flipper key in Macadam Bumper (I like playing flipper using shift keys).
  * _shift+arrow_ does move the second cursor, and _insert_ does copy letters that are under the second cursor. Basically, _insert_ key is mapped to the Amstrad's original _copy_ key.
  * _Page up_ will reset the Amstrad (it's my mute key...)

# Compatibility #

Please take a look at [MiST-board RomManagement](http://code.google.com/p/mist-board/wiki/RomManagement) project : about 2000 games were tested ok !

Known running [games](http://www.cpc-power.com) : Asphalt, **Bruce Lee**, **Buggy Boy**, Dan Dare 1 & 2, Exolon, **Donkey Kong**, **Fruity Frank**, **Hold-up**, Impossible Mission, **Macadam Bumper**, **Prince of Percia**, RAID (?), Rick Dangerous 1 & 2, **Sapiens**, Spin Dizzy, **Super Ski**, **Trail Blazer**, Wizard's Lair, 1942 1943, Classic Axiens, Classic Invaders,  Ghost'n'Goblins, Ghould'n'Ghosts, **Tempest**, Xevious, Salamander, Arkanoid, **Arkanoid Revenge of Doh**, **ChaseHQ**, **Bomb Jack**, Bomb Jack 2, 3D grand prix, Hyper bowl, Sorcery, Spherica, A view to a kill, Shinobi, Rygar, Realm, Bully's Sporting Darts, animated strip poker, Dizzy 7, Barbarian MH, Barbarian PA, Barbarian 2, **the sacred armor of Antiriad**, **Ikari warrior** (commando like), Bubble Ghost, Lode Runner, The Empire strikes back, Star wars, Gryzor (from romnation), **Boulder Dash**, Mange-Cailloux, Tetris 95, Maze Mania (Pacman variant), Locomotion, Express, **Light Force** (from RomManagement), Superkid In Space (from RomManagement), **Crazy Snake** (from RomManagement), **Prohibition** (from RomManagement).

Known running games in another VRAM area : **XOR** (LowerVRAM 01), **Crazy Car** (LowerVRAM 00), Crazy Car II (welcome overscan : LowerVRAM 10, game : LowerVRAM 00), **P47** (LowerVRAM 01), Paper Boy (LowerVRAM 01), Action Fighter (LowerVRAM 01), Classiques Volume 1 & 2 (LowerVRAM 00).

Known running demos from [CPCRulez demoscene](http://cpcrulez.fr/Scene_Demos/index.php) : -Circles, Crazy Demo, Genesis Demo, GPA Demo 1, IFE Demo, TMS Demo 2 (compacted one), **-Nibou**, Buck Demo Micro Escape Demo 7, Bugs party 2, CF Magic demo 2 (part3 <3), Crawling death demo, DSS intro v1.2, GPA Demo 2, JCP Mega Music, Majectic Demo, MCS demos (#2 <3), Murphy I the mega demo, Murphy II Death demo, Read Only Advert, Spaghetti Party 2, TBB Demo 3 (press a key after org), TBB last intro.

Known running demos from CPCRulez demoscene in another VRAM area : **OFE Tome 1 Little One** (LowerVRAM 01), Cast premiere (LowerVRAM 00 upperVRAM 01), Dragoon (LowerVRAM 00), Sky demo 1 (LowerVRAM 00), Sky demo 2 (LowerVRAM 01).

You can select VRAM area (LowerVRAM/upperVRAM) in OSD menu. Default one are 10 and 11.


---


# Gameplay Videos #
<a href='http://www.youtube.com/watch?feature=player_embedded&v=mTHb0kCSCdc' target='_blank'><img src='http://img.youtube.com/vi/mTHb0kCSCdc/0.jpg' width='425' height=344 /></a>

<a href='http://www.youtube.com/watch?feature=player_embedded&v=43itc-Kv-Wk' target='_blank'><img src='http://img.youtube.com/vi/43itc-Kv-Wk/0.jpg' width='425' height=344 /></a>


---


# Development details / acknowledgments #

This core is a port of FPGAmstrad from code for the NEXYS4 Diligent development board into the MiST board.

FPGAmstrad is a translation of JavaCPC from Java into VHDL (electronic language), essentially **reverse engineering** resulting in an original Amstrad clone.

JavaCPC is an Amstrad CPC 6128 emulator developed by Markus Hohmann.