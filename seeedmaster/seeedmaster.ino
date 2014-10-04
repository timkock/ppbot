// VERSION 0.1.2
#include <SPI.h>
#include <Andee.h>
#include <Wire.h>

// interface buttons
AndeeHelper btnForward;
AndeeHelper btnLeft;
AndeeHelper btnRight;
AndeeHelper btnBack;

void setup() {
  
  // Init Serial
  Serial.begin(115200);
  Wire.begin(4);
  
  // Initialize Andee
  Andee.begin();
  Andee.clear();
  
  // Push Buttons
  initAndee();
  btnForward.update();
  btnLeft.update();
  btnRight.update();
  btnBack.update();  
  
}

byte x = 0;

void initAndee() {
  
  btnForward.setId(0);
  btnForward.setType(BUTTON_IN);
  btnForward.setLocation(0,1,FULL);
  btnForward.setTitle("Forward");
  btnForward.requireAck(false);
  
  btnLeft.setId(1);
  btnLeft.setType(BUTTON_IN);
  btnLeft.setLocation(1,1,FULL);
  btnLeft.setTitle("Left");
  btnLeft.requireAck(false);
  
  btnRight.setId(2);
  btnRight.setType(BUTTON_IN);
  btnRight.setLocation(2,1,FULL);
  btnRight.setTitle("Right");
  btnRight.requireAck(false);
  
  btnBack.setId(3);
  btnBack.setType(BUTTON_IN);
  btnBack.setLocation(3,1,FULL);
  btnBack.setTitle("Reverse");
  btnBack.requireAck(false);
  
}

void loop() {
  
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write("x is ");        // sends five bytes
    Wire.write(x);              // sends one byte  
    Wire.endTransmission();    // stop transmitting
    
    x++;
    delay(500);
/*  
   // FORWARD
   if(btnForward.isPressed()) {
     btnForward.ack();
     // TODO:OUTSLAVE
     Serial.println("forward");
   }
   
   // BACKWARD
   if(btnBack.isPressed()) {
     btnBack.ack();
     // TODO:OUTSLAVE
     Serial.println("backward");
   }
   
   // LEFT
   if(btnLeft.isPressed()) {
     btnLeft.ack();
     // TODO:OUTSLAVE
     Serial.println("left");
   }
   
    // RIGHT
   if(btnRight.isPressed()) {
     btnRight.ack();
     // TODO:OUTSLAVE
     Serial.println("right");
   }
*/
}
