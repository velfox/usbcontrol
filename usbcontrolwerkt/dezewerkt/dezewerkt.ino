/***************************************************************************
  This is a library for the APDS9960 digital proximity, ambient light, RGB, and gesture sensor

  This sketch puts the sensor in gesture mode and decodes gestures.
  To use this, first put your hand close to the sensor to enable gesture mode.
  Then move your hand about 6" from the sensor in the up -> down, down -> up, 
  left -> right, or right -> left direction.

  Designed specifically to work with the Adafruit APDS9960 breakout
  ----> http://www.adafruit.com/products/3595

  These sensors use I2C to communicate. The device's I2C address is 0x39

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
#include <HID-Project.h>
#include <HID-Settings.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

const int buttonPin = 7;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton

// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(buttonPin, INPUT);
  Serial.begin(115200);
  
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");
  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
}

// the loop function runs over and over again forever
void loop() {
  //read a gesture from the device
    uint8_t gesture = apds.readGesture();
    if(gesture == APDS9960_DOWN){
        Consumer.write(MEDIA_VOL_MUTE);
      } 
    if(gesture == APDS9960_UP){
        Consumer.write(MEDIA_PLAY_PAUSE);
      } 
    if(gesture == APDS9960_LEFT) {
      Consumer.write(MEDIA_PREVIOUS);
    }
    
    if(gesture == APDS9960_RIGHT) {
      Consumer.write(MEDIA_NEXT);
    }

      // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    // increment the button counter
    // type out a message 
    Consumer.write(MEDIA_PREVIOUS);
  }
    previousButtonState = buttonState;
}
