#include <Servo.h>

int tStatus = 1;
int rStatus = 1;
Servo myservo;  // create servo object to control a servo
void setup() {
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  triggerTarget();
  delay(2000);
  resetTarget();
  delay(10000);
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

