#include <Servo.h>

int tStatus = 1;
int rStatus = 1;
Servo myservo;  // create servo object to control a servo
void setup() {
  myservo.attach(9);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(tStatus = HIGH && digitalRead(3) == LOW) triggerTarget();
  if(rStatus = HIGH && digitalRead(2) == LOW) resetTarget();
  tStatus = digitalRead(3);
  rStatus = digitalRead(2);
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

