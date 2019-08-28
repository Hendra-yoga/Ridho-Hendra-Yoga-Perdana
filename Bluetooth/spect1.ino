#include <SoftwareSerial.h>

#define BT_TX 2
#define BT_RX 3

SoftwareSerial mySerial(BT_TX, BT_RX);

char incoming_myserial;
//char incoming_serial;

#define redpin 11
#define greenpin 9
#define bluepin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
 
  if(mySerial.available())
  {
    Serial.write(mySerial.read());
    incoming_myserial = mySerial.read();
    if (incoming_myserial =="R")
    {
      set_color(0,255,255);
      delay(2000);
    }
    if (incoming_myserial =="B")
    {
      set_color(255,255,0);
      delay(2000);
    }
    if (incoming_myserial =="G")
    {
      set_color(255,0,255);
      delay(2000);
    }
    if (incoming_myserial =="A")
    {
      set_color(0,255,255);
      delay(1000);
      set_color(255,0,255);
      delay(1000);
      set_color(255,255,0);
      delay(1000);
    }
  }
  
  if(Serial.available())
  {
    delay(5);
    mySerial.write(Serial.read());
  }
  
  //delay(1000);
}

void set_color(int red, int green, int blue)
{
  analogWrite(redpin, red);
  analogWrite(greenpin, green);
  analogWrite(bluepin, blue);
}
