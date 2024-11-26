LEDs need pins capable of generating PWM signal, in pinout pdf they are marked with '~'.

For LCD we need I2C pins.

For LDR and potentiometers we need analog pins, those are ones with 'A' prefix.

|Device|Device pin|Arduino pin|Port|
|----|----|----|----|
|LCD|SDA|D18|PC4|
|LCD|SCL|D19|PC5|
|Button up|-|D7|PD7|
|Button down|-|D8|PB0|
|RGB LED room 1|-|D9|PB1|
|Button ok|-|D11|PB3|
|Button back|-|D12|PB4|
|Potentiometer LCD|-|A0(D14)|PC0|
|Potentiometer room 1|-|A1(D15)|PC1|
|Potentiometer 1 room 3|-|A2(D16)|PC2|
|Light sensor door|-|A3(D17)|PC3|
|Red LED room 3|-|~D3|PD3|
|Button room 3|-|D4|PD4|
|Green LED room 3|-|~D5|PD5|
|Blue LED room 3|-|~D6|PD6|
|Button 1 room 2|-|D0 (TX1)|PD0|
|Button sleep|-|D1 (RX1)|PD1|
|RGB LED room 2|-|D2|PD2|
|Potentiometer 2 room 3|-|A7|PC7|
|PIR sensor|-|D13|PB5|
|LED door|-|D10|PB2|
