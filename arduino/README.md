# Getting Started

1. Download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software) 1.6.8+
2. Open Arduino IDE with the code inside iot_nodemcu dir
3. Add support to ESP8266 > follow [this guide](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon)
4. Install  [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) library:
  1. Download repo as zip file
  2. Open Arduino IDE > Sketch > Include Library > Add .zip Library
5. Install [DHT Sensor](https://github.com/adafruit/DHT-sensor-library) library (same steps as before)
6. Copy `iot_nodemcu/_a_config.ino` into `iot_nodemcu/a_config.ino` and uncomment the code.
7. Set your configs defaults are set for pins as are described in the `electronics` directory
8. Compile the code

## Uploading code
1. Plug by USB the NodeMCU
2. Choose at Tools > Board > NodeMCU 1.0 (ESP-12E Module)
2. Set the correct port at Tools > Port
3. Press and hold FLASH button (RED on this box)
4. Press once RESET button (Blue on this box) - keep holding FLASH button
5. Click Upload code at Arduino IDE (without releasing FLASH)
6. It will compile and then when it starts uploading (showing uploading dots) > release FLASH button
