
#define trigPin 13                 
#define echoPin 12
#define buzzer 6                

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);  
  pinMode(buzzer, OUTPUT); 
}

void loop()
{
//******************************************************//
  // Sample Code
  long duration, distance;                   
  // (1) : generate ultrasonic waveform
  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               

  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);   

  distance = duration * 17 / 1000;
  

  if (distance >= 30 || distance <= 0)       
  {
    Serial.println(distance);
    Serial.println(" cm");
    tone(buzzer, 500);
    delay(1000);
  }
  else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");  
    noTone(buzzer);                     
  }
  delay(500);                                    
}
