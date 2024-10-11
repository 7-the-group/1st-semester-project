LEDs need pins capable of generating PWM signal, in pinout pdf they are marked with '~'.

For LCD we need I2C pins.

For LDR and potentiometers we need analog pins, those are ones with 'A' prefix.

|Device|Device pin|Arduino pin|
|----|----|----|
|LCD|SDA|A4|
|LCD|SCL|A5|
|Potentiometer room 1|-|A1|
|Potentiometer room 3|-|A2|
|Light sensor door|-|A3|

