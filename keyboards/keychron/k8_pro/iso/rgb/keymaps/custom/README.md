### Vivek Custom Key Map

### Software Required 
- Getting started guide : https://docs.qmk.fm/newbs_getting_started
- Install the latest version of dfu-util: https://dfu-util.sourceforge.net/
-  dfu-util building instructions
https://sourceforge.net/p/dfu-util/dfu-util/ci/master/tree/INSTALL

At a high level steps in building dfu-util
```
1. If building from git (not needed for release tarballs):
   Generate build system files (requires autoconf from autotools)

	./autogen.sh

2. Generate makefiles
   (Run ./configure --help to see configuration options)

	./configure

3. Build executables

	make

4. Install executables and manual pages (optional)

	make install

   If installing to a system directory use

	sudo make install
```


#### Useful QMK commands after installing QMK

Listing the Keyboards

`qmk list-keyboards`<br>

Checking the env
```
$qmk env
QMK_HOME="/home/xxxx/Development/keychron/qmk_firmware"
QMK_FIRMWARE="/home/xxxx/Development/keychron/qmk_firmware"
QMK_VERBOSE="False"
QMK_DATETIME_FMT="%Y-%m-%d %H:%M:%S"
QMK_LOG_FMT="%(levelname)s %(message)s"
QMK_LOG_FILE_FMT="[%(levelname)s] [%(asctime)s] [file:%(pathname)s] [line:%(lineno)d] %(message)s"
QMK_LOG_FILE_LEVEL="info"
QMK_LOG_FILE="None"
QMK_COLOR="True"
QMK_UNICODE="True"
QMK_INTERACTIVE="False"
```

Setting the qmk home folder
```
qmk setup -H /home/xxxx/Development/keychron/qmk_firmware
```


Setting the default user keyboard
```
$qmk config user.keyboard=keychron/k8_pro/iso/rgb
```

Checking the config 
```
$qmk config                                                                                        
user.keyboard=keychron/k8_pro/iso/rgb
user.qmk_home=/home/xxxx/Development/keychron/qmk_firmware

```

Compiling the custom keyboard 
```
$qmk compile -kb keychron/k8_pro/iso/rgb -km custom                                                 ✔  10151  100% (...) 🔋  192.168.0.66 
Ψ Compiling keymap with gmake --jobs=1 keychron/k8_pro/iso/rgb:custom


QMK Firmware 0.14.29
Making keychron/k8_pro/iso/rgb with keymap custom

arm-none-eabi-gcc (15:10.3-2021.07-4) 10.3.1 20210621 (release)
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text	   data	    bss	    dec	    hex	filename
      0	  62874	      0	  62874	   f59a	keychron_k8_pro_iso_rgb_custom.bin

Compiling: quantum/via.c                                                                            [OK]
Linking: .build/keychron_k8_pro_iso_rgb_custom.elf                                                  [OK]
Creating binary load file for flashing: .build/keychron_k8_pro_iso_rgb_custom.bin                   [OK]
Creating load file for flashing: .build/keychron_k8_pro_iso_rgb_custom.hex                          [OK]

Size after:
   text	   data	    bss	    dec	    hex	filename
      0	  62874	      0	  62874	   f59a	keychron_k8_pro_iso_rgb_custom.bin

Copying keychron_k8_pro_iso_rgb_custom.bin to qmk_firmware folder                                   [OK]
(Firmware size check does not yet support STM32L432; skipping)
 
 
$ll keychron_k8_pro_iso_rgb_custom.bin                                                              ✔  10151  100% (...) 🔋  192.168.0.66 
Permissions Size User  Date Modified Date Created Date Accessed Name
.rwxrwxr-x   63k xxxx  4 Jul 22:16  -             4 Jul 22:16   keychron_k8_pro_iso_rgb_custom.bin

 
```

Flashing the custom keyboard

```
╰─ qmk flash -kb keychron/k8_pro/iso/rgb -km custom                                                   ✔  10152  100% (...) 🔋  192.168.0.66 
Ψ Compiling keymap with gmake --jobs=1 keychron/k8_pro/iso/rgb:custom:flash


QMK Firmware 0.14.29
Making keychron/k8_pro/iso/rgb with keymap custom and target flash

arm-none-eabi-gcc (15:10.3-2021.07-4) 10.3.1 20210621 (release)
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text	   data	    bss	    dec	    hex	filename
      0	  62874	      0	  62874	   f59a	keychron_k8_pro_iso_rgb_custom.bin

Compiling: quantum/via.c                                                                            [OK]
Linking: .build/keychron_k8_pro_iso_rgb_custom.elf                                                  [OK]
Creating binary load file for flashing: .build/keychron_k8_pro_iso_rgb_custom.bin                   [OK]
Creating load file for flashing: .build/keychron_k8_pro_iso_rgb_custom.hex                          [OK]

Size after:
   text	   data	    bss	    dec	    hex	filename
      0	  62874	      0	  62874	   f59a	keychron_k8_pro_iso_rgb_custom.bin

Copying keychron_k8_pro_iso_rgb_custom.bin to qmk_firmware folder                                   [OK]
Flashing for bootloader: stm32-dfu
Bootloader not found. Make sure the board is in bootloader mode. See https://docs.qmk.fm/#/newbs_flashing
 Trying again every 0.5s (Ctrl+C to cancel).....^[.^[^[^[^[^[^[^[^[^[^[^[^[^[^[^[.^[^[^[^[........
dfu-util 0.11

Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
Copyright 2010-2021 Tormod Volden and Stefan Schmidt
This program is Free Software and has ABSOLUTELY NO WARRANTY
Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

Opening DFU capable USB device...
Device ID 0483:df11
Device DFU version 011a
Claiming USB DFU Interface...
Setting Alternate Interface #0 ...
Determining device status...
DFU state(10) = dfuERROR, status(10) = Device's firmware is corrupt. It cannot return to run-time (non-DFU) operations
Clearing status
Determining device status...
DFU state(2) = dfuIDLE, status(0) = No error condition is present
DFU mode device DFU version 011a
Device returned transfer size 2048
DfuSe interface name: "Internal Flash  "
Downloading element to address = 0x08000000, size = 62908
Erase   	[=========================] 100%        62908 bytes
Erase    done.
Download	[===============          ]  61%        38912 bytes

```
### How do I put my Keychron K8 in Bootloader mode 
To put your Keychron K8 Pro into bootloader mode, you can either press and hold the Esc key while plugging in the keyboard, or remove the spacebar keycap to reveal the reset button, hold it while connecting the keyboard.
Detailed Steps:

    1. Option 1 (Esc Key):
        Unplug the K8 Pro.
        Hold down the Esc key (top left corner).
        Plug the USB cable back into the keyboard while continuing to hold the Esc key.
        Release the Esc key after plugging in the keyboard. 
    2. Option 2 (Reset Button):
        Unplug the K8 Pro.
        Remove the spacebar keycap.
        Identify the small, four-legged reset button on the PCB, typically located to the left of the spacebar switch.
        Hold down the reset button with a pen, keycap puller, or other suitable tool.
        Plug the USB cable back into the keyboard while continuing to hold the reset button.
        Release the reset button after the keyboard is connected. 



### Debug logging 
Set the following in rules.mk

```
CONSOLE_ENABLE = yes
```

Then set the following callback method in keymap.c
```

void keyboard_post_init_user(void) {
    //Remove the following line to enable debugging
    debug_enable = true;  // Enable verbose debugging
}

```

The use the following methods to print debug prints 

```
dprintf("fnished: tap code : %d \n", pair->tap);
```


#### Links
- Details on Tap Dance: https://docs.qmk.fm/features/tap_dance#how-to-use
- Source Code on various Data Types : process_tap_dance.h
- Attempting to setup Home Row Mods https://precondition.github.io/home-row-mods#hold-on-other-key-press
- Factory Resetting your keyboard - https://www.keychron.com/pages/how-to-factory-reset-or-use-the-launcher-web-app-to-flash-firmware-for-your-keyboard
- 

