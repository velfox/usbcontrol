#include <HID-Project.h>
#include <HID-Settings.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

const int buttonPin = 10;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton

//afstand
const int trigPin = 14;
const int echoPin = 15;

long duration;
int dCm, dInch;


// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(buttonPin, INPUT);
  Serial.begin(115200);
  pinMode(16,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");
  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
  digitalWrite(16, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(16, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

// the loop function runs over and over again forever
void loop() {
  //read a gesture from the device
    uint8_t gesture = apds.readGesture();
    if(gesture == APDS9960_DOWN){
        digitalWrite(16, HIGH);
        Consumer.write(MEDIA_VOL_MUTE);
        delay(100);
        digitalWrite(16, LOW);
      } 
    if(gesture == APDS9960_UP){
        digitalWrite(16, HIGH);
        Consumer.write(MEDIA_PLAY_PAUSE);
        delay(100);
        digitalWrite(16, LOW);
      } 
    if(gesture == APDS9960_LEFT) {
      digitalWrite(16, HIGH);
      Consumer.write(MEDIA_PREVIOUS);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(7, HIGH);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(16, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(16, LOW);
      digitalWrite(16, LOW);
    }
    
    if(gesture == APDS9960_RIGHT) {
      digitalWrite(16, HIGH);
      Consumer.write(MEDIA_NEXT);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(7, HIGH);
        delay(100);
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(16, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(16, LOW);
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
    digitalWrite(16, HIGH);
    delay(100);
    digitalWrite(16, LOW);
  }
    previousButtonState = buttonState;

    //geluuid
//
//    digitalWrite(trigPin, LOW);
//    delayMicroseconds(2);
//    
//    digitalWrite(trigPin, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trigPin, LOW);
//    
//    duration = pulseIn(echoPin, HIGH);
//    dCm = duration*0.034/2;
//    
//    if(dCm<2){
//       digitalWrite(6,HIGH);
//       digitalWrite(7,HIGH);
//       digitalWrite(8,HIGH);
//       digitalWrite(9,HIGH);
//    }
//    else if(dCm>2&&dCm < 5 ){
//       digitalWrite(6,LOW);
//       digitalWrite(7,LOW);
//       digitalWrite(8,LOW);
//       digitalWrite(9,LOW);
//    }
//    else if(dCm > 5 && dCm <10){
//       digitalWrite(6,HIGH);
//       digitalWrite(7,LOW);
//       digitalWrite(8,LOW);
//       digitalWrite(9,LOW);
//    }
//    else if(dCm > 10 && dCm <15){
//       digitalWrite(6,HIGH);
//       digitalWrite(7,HIGH);
//       digitalWrite(8,LOW);
//       digitalWrite(9,LOW);  
//    }
//    else if(dCm > 15 && dCm <20){
//       digitalWrite(6,HIGH);
//       digitalWrite(7,HIGH);
//       digitalWrite(8,HIGH);
//       digitalWrite(9,LOW);
//    }else if(dCm>20){
//       digitalWrite(6,HIGH);
//       digitalWrite(7,HIGH);
//       digitalWrite(8,HIGH);
//       digitalWrite(9,HIGH);
//    }
}
