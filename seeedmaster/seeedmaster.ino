// VERSION 0.1.2
#include <SPI.h>
#include <Andee.h>
#include <Wire.h>

// interface buttons
AndeeHelper btnForward;
AndeeHelper btnLeft;
AndeeHelper btnRight;
AndeeHelper btnBack;

// COMMANDS
const String FORWARD  = "FORWARD\n";
const String BACKWARD = "BACKWARD\n";
const String LEFT     = "LEFT\n";
const String RIGHT    = "RIGHT\n";

void setup() {
  
  // Initialize Andee
  Andee.begin();
  Andee.clear();
  
  // Push Buttons
  initAndee();
  btnForward.update();
  btnLeft.update();
  btnRight.update();
  btnBack.update();  
  
  // Init Wire & Serial
  Wire.begin(4);
  Serial.begin(115200);
  
}

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

void sendCmd(String cmd) {
  Serial.print("Sending: ");
  Serial.print(cmd);
  Serial.println();
  Wire.beginTransmission(4); // transmit to device #4
  for (int i = 0; i < sizeof(cmd) - 1; i++){
    Wire.write(cmd[i]);
  }
  Wire.endTransmission();    // stop transmitting
}

void loop() {
 
   // FORWARD
   if(btnForward.isPressed()) {
     btnForward.ack();
     sendCmd(FORWARD);
   }
   
   // BACKWARD
   if(btnBack.isPressed()) {
     btnBack.ack();
     sendCmd(BACKWARD);
   }
   
   // LEFT
   if(btnLeft.isPressed()) {
     btnLeft.ack();
     sendCmd(LEFT);
   }
   
    // RIGHT
   if(btnRight.isPressed()) {
     btnRight.ack();
     sendCmd(RIGHT);
   }
   
}
