// constants (3,8,9,11,12,13)
const int MOTORA = 12;
const int BREAKA = 9;
const int SPEEDA = 3;
const int MOTORB = 13;
const int BREAKB = 8;
const int SPEEDB = 11;

void setup() {
  
  // Init Serial
  Serial.begin(115200);
  
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

bool dir = false;
void loop() {
  
  // rock that motherfucker
  if(dir) {
    goForward(500);
  } else {
    goBack(500);
  }
  dir = !dir;
  
}
