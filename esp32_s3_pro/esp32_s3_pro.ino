#include <Arduino.h>
#include "MiniPID.h"


#define M1_INT1 12 
#define M1_INT2 11 
#define M2_INT1 10 
#define M2_INT2 9 
#define M3_INT1 8 
#define M3_INT2 7
#define M4_INT1 6
#define M4_INT2 5

#define HULL0   A0
#define HULL1   A1
#define HULL2   A2

MiniPID pid(1,0,0);

void setup() {

  Serial.begin(115200);
  Serial.println("Starting running this bitch...");

  pinMode(M1_INT1, OUTPUT);
  pinMode(M1_INT2, OUTPUT);
  pinMode(M2_INT1, OUTPUT);
  pinMode(M2_INT2, OUTPUT);
  pinMode(M3_INT1, OUTPUT);
  pinMode(M3_INT2, OUTPUT);
  pinMode(M4_INT1, OUTPUT);
  pinMode(M4_INT2, OUTPUT);

  
}

void loop() {

  int hull0 = analogRead(HULL0);
  int hull1 = analogRead(HULL1);
  int hull2 = analogRead(HULL2);

  double output = pid.getOutput(0, 2);

  analogWrite(12,2);		
  delay(1000);

  Serial.print("The system is running.\n");
  Serial.print(output, 5);
  Serial.print("\n");

  
}






