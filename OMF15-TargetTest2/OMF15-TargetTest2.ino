#include <Servo.h>

#define RESET 8
#define TRIG 9

int tStatus = 1;
int rStatus = 1;

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(57600);
  
  pinMode(TRIG, INPUT);
  pinMode(RESET, INPUT);
  
  myservo.attach(9);

  Serial.println("ready");
}

void loop() {
  // put your main code here, to run repeatedly:
//  triggerTarget();
//  delay(2000);
//  resetTarget();
//  delay(10000);

    if (digitalRead(9) == 1)
    {
        Serial.println("trigger");
        triggerTarget();

        delay(1000);

        resetTarget();
    }
    if (digitalRead(8) == 1)
    {
        Serial.println("reset");
        resetTarget();
    }

    delay(50);
}

void resetTarget(){
  myservo.write(180);
  delay(750);
  myservo.write(50);
  delay(250);
}

void triggerTarget(){
  myservo.write(20);
  delay(500);
  myservo.write(50);
  delay(250);

}

