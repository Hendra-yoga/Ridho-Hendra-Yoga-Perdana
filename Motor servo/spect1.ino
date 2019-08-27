#include <Servo.h>

Servo myServo;
int angle = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long tick = millis();
  for (int i=0; i<10; i++)
  {
  for (angle = 0;angle < 180; angle++)
  {
    myServo.write(angle);
    delay(20);
  }
  for (angle = 180;angle > 0; angle--)
  {
    myServo.write(angle);
    delay(20);
  }
  }
  Serial.println(millis() - tick);
}

/* result 54.208 second for 10 times rotation, so the conclusion is the servo motor 
 *  has 11 Rpm, 1 rotation need 5.45 second and 60 degree need 0.9 second.
 */
