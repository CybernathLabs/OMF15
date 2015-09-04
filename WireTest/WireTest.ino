#include <Wire.h>
/*
 * This code is for the trinkets. Addresses 2 and 3.
 * They have a button connected to pin 4, 
 * which pulls to ground when pressed, illuminating pin 13,
 * and setting triggered = true.
 * 
 * Responds to requests for information with the triggered value.
 * Responds to incoming / received input to reset the board.
 * 
 * See other file for additional hardware info.
 */
int lastRead = 1;
int triggered = 0;

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent);
  pinMode(4,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop()
{
  if(lastRead == HIGH && digitalRead(4) == LOW ){
    triggered = 1;
  }
  
    digitalWrite(13,triggered);
  
  lastRead = digitalRead(4);
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  Wire.write(triggered); // respond with message of 6 bytes
                       // as expected by master
}
void receiveEvent(int howMuch){
  int d = Wire.read();
  if(d == 1){
    triggered = 0;
  }

}

