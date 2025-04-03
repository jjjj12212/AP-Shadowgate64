# Shadowgate64 ROM Hack for Archipelago
This repository is designed to work with [Archipelago-Shadowgate64](https://github.com/jjjj12212/Archipelago-Shadowgate64/) project.

# How to build
## Dependencies
In the n64/tools folder, you will need to place:
* [libdragon/](https://github.com/DragonMinded/libdragon)
* [mips64/](https://github.com/DragonMinded/libdragon/releases/tag/toolchain-continuous-prerelease)
* [armips](https://github.com/Kingcom/armips/releases)

In the n64/rom folder, you will need to place a file called `Shadowgate64.z64`. This file cannot be byte-swapped.

Run `make`, then run patch.py inside the rom folder to create the patchfile.
