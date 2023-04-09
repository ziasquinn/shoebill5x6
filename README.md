# shoebill5x6
A joystick-L / trackball-R dactyl manuform handwired keyboard running off QMK firmware. The joystick is analog-input and the trackball uses PWM

## design

This keyboard is a modified design of [the trackbeast](https://github.com/davekincade/track_beast) for the trackball right-side, with a rotated OLED screen. Additionally, [this design](https://gitlab.com/keyboards1/dm_r_joy)  has been modified to move the joystick to the left side. It was modified and manufactured by [DIYKeyboards.com](DIYKeyboards.com) by the owner, Jesse. This design has a Bongocat that reacts to typing input embedded in the status OLED. It has no RGB by default and no speakers, but can easily accept those modifications with the Elite-C due to the extra pin outs.

It uses [Elite-C controllers](https://deskthority.net/wiki/Elite-C) and is powered by [QMK firmware](https://qmk.fm/).

## building and construction

You need these supplies to handwire and build the keyboard.

### tools
####   1. Soldering Iron / station
####    2. Solder (I used leaded solder)
####    3. Tweezers (I really recommend some fine pointed tweezers for manipulating the wire)
####    4. Hot glue gun
####    5. Optional: Helping hands station
    
## bill of materials (bom)

You need a number of knick knacks and hardware to complete the build. If you want the main ingredients in a single kit (diodes, 2m of cable (stranded), hot melt inserts and screws, reset switches), [you can buy this kit](https://www.diykeyboards.com/parts/product/dmf-hardware-kit) alongside your preferred microcontrollers. 

####    1. Keyboard switches x75
####   2. Keycaps (1U-1.5U) x75
####   3. Wires, x-acto blade or small box cutter. Get several feet. Solid core is preferred due to the method of stripping the wires to expose the core rather than dealing with stranded wire getting crushed.
####   4. [1n4148 diodes](https://www.digikey.com/product-detail/en/on-semiconductor/1N4148/1N4148FS-ND/458603) x80, get extras just incase.
####   5. [Elite-C](https://www.diykeyboards.com/parts/electronics/product/elite-c) or [Pro-Micro](https://www.diykeyboards.com/parts/product/pro-micro-atmega32u4-5v-16mhz-controller) controller boards x2 
####   6. [Rj9 connectors](https://www.amazon.com/gp/product/B0BG7CVNQJ/) x2 with a handset cable (RJ9 sized; this is the narrower variant of the more classic rj11/rj45 phone jack) OR 3.5 aux cable TRRS jacks x2 (+ an aux cable)
####   7. [Type-C connectors, Male-to-Female](https://www.amazon.com/gp/product/B08BYRH9DR) x2, as short as possible
####   8. USB-C cable x1
####   9. [Reset button](https://www.aliexpress.com/item/1058764733.html?spm=a2g0s.9042311.0.0.1f734c4dmEJWHA) x2 -- allows you to put the keyboard halves into bootloader mode without having to bridge RST+GND or use Quantum keycodes
####   10. [128x32 SSD1306 driven OLED screen](https://www.diykeyboards.com/parts/electronics/product/p128x32-oled-lcd-display-ssd1306-driver) x1 make sure you're not occupying SDA/SCL (D1, D0 on Elite-C) pins.
####   11. 34-35mm trackball x1
####   12. [PMW-3360 motion sensor](https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/) x1
####   13. [Roller bearings](https://smile.amazon.com/gp/product/B00ZHSQX42) x3
####   14. [6mm Steel dowels](https://www.amazon.com/dp/B0BFS38R1S) for the trackball x3 
####   15. Joystick 

## wiring guide

For a more thorough wiring guide, please see Derek's "[Complete Idiot's Guide to Building a Dactyl Manuform](https://medium.com/swlh/complete-idiot-guide-for-building-a-dactyl-manuform-keyboard-53454845b065)" for the foundational information about diodes, column and row arrangement, and general wiring practice and advice. For trackball-side information, see the more complete [Dave Kincade guide here](https://medium.com/@kincade/track-beast-build-log-a-trackball-dactyl-manuform-19eaa0880222).

Basics are this: 

1. diodes go black-away from switch pin/brown toward the switch pin. 
2. note your pinouts, you will modify your config.h to assign the proper rows/columns to each key. between halves, rows stay the same but columns invert, ex: the farthest column from the controller swaps places with the closest column in terms of wiring.

for example my config.h has this defined:
#### // wiring of each half
#### define MATRIX_COL_PINS { B0, D4, C6, D7, E6, B4 }
#### define MATRIX_ROW_PINS { B5, B7, D5, C7, F1, F0 }

3. Note the serial pin used, I used D3
4. strip the wire for columns with your razer blade to expose a section of the wire but keep the rest insulated. This will save a ton of time and effort instead of cutting 4-5 lengths of wire and soldering each one on independently of each other. You want either columns or rows insulated as they will likely cross over each other.


### joystick modification

In relation to the joystick on the left side, assign the controller board pins to unused pins on the controller. Note these for later firmware building. For example, mine looks like this:

Joystick:
1. GND = GND
2. +5V = VCC
3. VRx = F5
4. VRy = F6
5. SW = F4

### trackball modification

Same for the trackball. I used separate sections of the Elite-C (the right-hand side) to allow myself to assign independent pins to the trackball and to the joystick without overlap for ease of coding. For example, mine looks like this:

Trackball:
1. GD = GND
2. MT = XXX (unused)
3. SS = F7
4. SC = B1
5. M0 = B2
6. MI = B3
7. VI = VCC

You can clone this repo and modify the files as you see fit.

You may need to modify /home/$USER/qmk_firmware/platforms/avr/__pin_defs.h_ to define extra Elite-C pins. 

#--WIP--

 
