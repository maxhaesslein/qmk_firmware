# hex layout
# by maxhaesslein 2017-2018

## planck rev 4:

build from root with
    make planck/rev4:hex

then flash firmware; press reset button on keyboard, then
    sudo dfu-programmer atmega32u4 erase
    sudo dfu-programmer atmega32u4 flash planck_rev4_hex.hex
    sudo dfu-programmer atmega32u4 reset

## planck rev 6:

build from root with
	make planck/rev6:hex:dfu-util
