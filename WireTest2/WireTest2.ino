#include <Wire.h>
/* 
 *  This is the code running on an UNO.
 *  Hardware setup consists of 2 Trinket Pro's and and UNO
 *  Pins A4 and A5 are connected between all three boards.
 *  They also share a ground connection.
 *  
 *  Currently, the uno is sending 5v to the "bat" line of the
 *  trinkets, but they could be externally powered instead.
 *  
 *  Working together, the UNO queries each trinket for it's 
 *  status, triggered or not, and when it receives a "triggered" 
 *  from both boards, it blinks pin 13, and sends them a reset message.
 */
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  Serial.println("yup");
  pinMode(13,OUTPUT);
}

void loop()
{
  Wire.requestFrom(2, 1);    // request 6 bytes from slave device #2
    int c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character

Wire.requestFrom(3, 1);    // request 6 bytes from slave device #2
  int c2 = Wire.read(); // receive a byte as character
    Serial.print(c2);         // print the character
 
  if(c == 1 && c2 == 1){
    Serial.print("yes");
    digitalWrite(13,HIGH);
    delay(1000);
    Wire.beginTransmission(2);
    Wire.write(1);
    Wire.endTransmission();
    Wire.beginTransmission(3);
    Wire.write(1);
    Wire.endTransmission();
    digitalWrite(13,LOW);
  }else{
    digitalWrite(13,LOW);
  }
  Serial.println(".");
  delay(500);
}
