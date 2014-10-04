// VERSION 0.1.2
#include <Wire.h>

// constants (3,8,9,11,12,13)
const int MOTORA = 12;
const int BREAKA = 9;
const int SPEEDA = 3;
const int MOTORB = 13;
const int BREAKB = 8;
const int SPEEDB = 11;

// COMMANDS
const String FORWARD  = "FORWARD";
const String BACKWARD = "BACKWARD";
const String LEFT     = "LEFT";
const String RIGHT    = "RIGHT";

void setup() {
  
  
  // Motor A
  pinMode(MOTORA, OUTPUT); // Motor Channel A
  pinMode(BREAKA, OUTPUT); // Break Channel A
  pinMode(SPEEDA, OUTPUT); // Speed Channel A
  
  // Motor B
  pinMode(MOTORB, OUTPUT); // Motor Channel B
  pinMode(BREAKB, OUTPUT); // Break Channel B
  pinMode(SPEEDB, OUTPUT); // Speed Channel B
  
  // BREAK A && B
  digitalWrite(BREAKA, HIGH); // engage the Brake for Channel A
  digitalWrite(BREAKB, HIGH); // engage the Brake for Channel B 
  
  // Initialize Wire
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  
  // Init Serial
  Serial.begin(115200);
 
}

void goForward(int dist) {
  
    // MOTOR A && B
    digitalWrite(MOTORA, LOW); // Establishes forward direction of Channel A
    digitalWrite(MOTORB, LOW); // Establishes forward direction of Channel B
    digitalWrite(BREAKA, LOW); // Disengage the Brake for Channel A
    digitalWrite(BREAKB, LOW); // Disengage the Brake for Channel B
    analogWrite(SPEEDA, 255);  // Spins the motor on Channel A at speed given
    analogWrite(SPEEDB, 255);  // Spins the motor on Channel B at Speed given  
    
    delay(dist);
  
    // STOP A && B
    digitalWrite(BREAKA, HIGH); // engage the Brake for Channel A
    digitalWrite(BREAKB, HIGH); // engage the Brake for Channel B  
}

void goBack(int dist) {
  
    // MOTOR A && B
    digitalWrite(MOTORA, HIGH); // Establishes backward direction of Channel A
    digitalWrite(MOTORB, HIGH); // Establishes backward direction of Channel B
    digitalWrite(BREAKA, LOW); // Disengage the Brake for Channel A
    digitalWrite(BREAKB, LOW); // Disengage the Brake for Channel B
    analogWrite(SPEEDA, 255);  // Spins the motor on Channel A at speed given
    analogWrite(SPEEDB, 255);  // Spins the motor on Channel B at Speed given  
    
    delay(dist);
  
    // STOP A && B
    digitalWrite(BREAKA, HIGH); // engage the Brake for Channel A
    digitalWrite(BREAKB, HIGH); // engage the Brake for Channel B  
}

void receiveEvent(int howMany) {
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
}

void loop() {
}
