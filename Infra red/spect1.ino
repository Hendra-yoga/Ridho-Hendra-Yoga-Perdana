void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() 
{
  int volt;
  volt = map(analogRead(A0),0,1023,0,5000);
  Serial.print((21.61/(volt-0.1696))*1000);
  Serial.println(" cm");
  tone(6,400);
  delay(200);
  noTone(6);
  delay(300);
}
