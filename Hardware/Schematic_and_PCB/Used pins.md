LEDs need pins capable of generating PWM signal, in pinout pdf they are marked with '~'.

For LCD we need I2C pins.

For LDR and potentiometers we need analog pins, those are ones with 'A' prefix.

|Device|Device pin|Arduino pin|
|----|----|----|
|LCD|SDA|D18|
|LCD|SCL|D19|
|Button up|-|D7|
|Button down|-|D8|
|RGB LED room 1|-|D9|
|Button ok|-|D11|
|Button back|-|D12|
|Potentiometer LCD|-|A0(D14)|
|Potentiometer room 1|-|A1(D15)|
|Potentiometer 1 room 3|-|A2(D16)|
|Light sensor door|-|A3(D17)|
|Red LED room 3|-|~D3|
|Button room 3|-|D4|
|Green LED room 3|-|~D5|
|Blue LED room 3|-|~D6|
|Button 1 room 2|-|D0 (TX1)|
|Button sleep|-|D1 (RX1)|
|RGB LED room 2|-|D2|
|Potentiometer 2 room 3|-|A7|
