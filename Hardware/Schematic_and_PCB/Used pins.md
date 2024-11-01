LEDs need pins capable of generating PWM signal, in pinout pdf they are marked with '~'.

For LCD we need I2C pins.

For LDR and potentiometers we need analog pins, those are ones with 'A' prefix.

|Device|Device pin|Arduino pin|Port|
|----|----|----|----|
|LCD|SDA|D18|PA2|
|LCD|SCL|D19|PA3|
|Button up|-|D7|PA1|
|Button down|-|D8|PE3|
|RGB LED room 1|-|D9|PB0|
|Button ok|-|D11|PE0|
|Button back|-|D12|PE1|
|Potentiometer LCD|-|A0(D14)|PD3|
|Potentiometer room 1|-|A1(D15)|PD2|
|Potentiometer 1 room 3|-|A2(D16)|PD1|
|Light sensor door|-|A3(D17)|PD0|
|Red LED room 3|-|~D3|PF5|
|Button room 3|-|D4|PC6|
|Green LED room 3|-|~D5|PB2|
|Blue LED room 3|-|~D6|PF4|
|Button 1 room 2|-|D0 (TX1)|PC4|
|Button sleep|-|D1 (RX1)|PC5|
|RGB LED room 2|-|D2|PA0|
|Potentiometer 2 room 3|-|A7|PD5|
