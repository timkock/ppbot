#include <SPI.h>
#include <Andee.h>

// interface buttons
AndeeHelper btnForward;
AndeeHelper btnLeft;
AndeeHelper btnRight;
AndeeHelper btnBack;

void setup() {
  
  // Init Serial
  Serial.begin(115200);
  
  // Motor A
  pinMode(12, OUTPUT); // Motor Channel A
  pinMode(9, OUTPUT);  // Break Channel A
  pinMode(3, OUTPUT);  // Speed Channel A
  
  // Motor B
  pinMode(13, OUTPUT); // Motor Channel B
  pinMode(8, OUTPUT);  // Break Channel B
  pinMode(11, OUTPUT); // Speed Channel B
  
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
  
   // FORWARD
   if(btnForward.isPressed()) {
     btnForward.ack();
     Serial.println("forward");
   }
   
   // BACKWARD
   if(btnBack.isPressed()) {
     btnBack.ack();
     Serial.println("backward");
   }
   
   // LEFT
   if(btnLeft.isPressed()) {
     btnLeft.ack();
     Serial.println("left");
   }
   
    // RIGHT
   if(btnRight.isPressed()) {
     btnRight.ack();
     Serial.println("right");
   }
   
}
