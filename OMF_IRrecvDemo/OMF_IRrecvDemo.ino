/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 2;
#define GREEN 3
#define BLUE 4
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,HIGH);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0x2107EE11){
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,LOW);
      delay(500);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,HIGH);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
