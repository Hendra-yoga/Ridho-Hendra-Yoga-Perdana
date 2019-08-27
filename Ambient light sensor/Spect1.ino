
#define LIGHT A3
#define LED A5
#define Buzzer 6

void setup() {
  Serial.begin(9600);

  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 0, 255);
  //Serial.print("LIGHT : ");
  Serial.println(value);
  //Serial.println(value);
  if (value > 200)
  {
    analogWrite(LED,data);
    tone(Buzzer, 500);
    delay(500);
    noTone(Buzzer);
    delay(500);
  }
  noTone(Buzzer);
  delay(500);
}
