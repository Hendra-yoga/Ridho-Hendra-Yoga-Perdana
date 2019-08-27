
#define trigPin 13                 
#define echoPin 12
//#define buzzer 6   
            
#define redpin 11
#define greenpin 5
#define bluepin 3

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);  
  //pinMode(buzzer, OUTPUT); 
  
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  
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
  

  set_color(distance,255,255);
  Serial.println(distance);
  /*
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
  */
  delay(1000);                       
}


void set_color(int red, int green, int blue)
{
  analogWrite(redpin, red*10);
  analogWrite(greenpin, 255);
  analogWrite(bluepin, 255);
}
