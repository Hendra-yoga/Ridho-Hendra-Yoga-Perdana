#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

#define deviceID "firdauD1566951696016"
#define authnRqtNo "5x1267166"
#define extrSysID "OPEN_TCP_001PTL001_1000007608"

#define WIFI_SSID "ICT-LAB-2.4G"
#define WIFI_PASS "12345678"
#define TAG_ID "count"

IoTMakers g_im;

#define buzzer 6
#define trigPin1 11
#define trigPin2 12
#define trigPin3 13

#define echoPin1 A1
#define echoPin2 A2
#define echoPin3 A3
#define echoPin4 A4
#define echoPin5 A5
#define ultra1 2
#define ultra2 3
#define ultra3 4
#define ultra4 5
#define ultra5 7

int j = 0;

void init_iotmakers()
{
  while (1)
  {
    Serial.print(F("Connect to AP..."));
    while (g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);

    Serial.print(F("Connect to platform..."));
    while (g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));

    Serial.print(F("Auth..."));
    if (g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_iotmakers();
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
  pinMode(ultra1, OUTPUT);
  pinMode(ultra2, OUTPUT);
  pinMode(ultra3, OUTPUT);
  pinMode(ultra4, OUTPUT);
  pinMode(ultra5, OUTPUT);
}

void loop() {
  long duration, distance;


  
    if(g_im.isServerDisconnected() == 1)
    {
    init_iotmakers();
    }
  
  for (int i = 0; i < 5; i++)
  {
    if (i == 0)
    {
      digitalWrite(ultra1, 1);
      digitalWrite(ultra2, 0);
      digitalWrite(ultra3, 0);
      digitalWrite(ultra4, 0);
      digitalWrite(ultra5, 0);
    }
    if (i == 1)
    {
      digitalWrite(ultra1, 0);
      digitalWrite(ultra2, 1);
      digitalWrite(ultra3, 0);
      digitalWrite(ultra4, 0);
      digitalWrite(ultra5, 0);
    }
    if (i == 2)
    {
      digitalWrite(ultra1, 0);
      digitalWrite(ultra2, 0);
      digitalWrite(ultra3, 1);
      digitalWrite(ultra4, 0);
      digitalWrite(ultra5, 0);
    }
    if (i == 3)
    {
      digitalWrite(ultra1, 0);
      digitalWrite(ultra2, 0);
      digitalWrite(ultra3, 0);
      digitalWrite(ultra4, 1);
      digitalWrite(ultra5, 0);
    }
    if (i == 4)
    {
      digitalWrite(ultra1, 0);
      digitalWrite(ultra2, 0);
      digitalWrite(ultra3, 0);
      digitalWrite(ultra4, 0);
      digitalWrite(ultra5, 1);
    }
    delay(100);
    if (i == 0)
    {
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);

      duration = pulseIn(echoPin1, HIGH);
    }

    if (i == 1)
    {
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);

      duration = pulseIn(echoPin2, HIGH);
    }
    
    if (i == 2)
    {
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);

      duration = pulseIn(echoPin3, HIGH);
    }

    if (i == 3)
    {
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);

      duration = pulseIn(echoPin4, HIGH);
    }
    
    if (i == 4)
    {
      digitalWrite(trigPin3, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin3, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin3, LOW);

      duration = pulseIn(echoPin5, HIGH);
    }
    distance = duration * 17 / 1000;


    if (distance >= 10 || distance <= 0)
    {
      Serial.print("Ultrasonic ");
      Serial.print(i);
      Serial.print(" : ");
      Serial.println(distance);
      Serial.println("to far");
      tone(buzzer, 500);
      delay(1000);
      noTone(buzzer);
      delay(500);
      tone(buzzer, 500);
      delay(1000);
      noTone(buzzer);
      delay(500);
    }
    else
    {
      Serial.print("Ultrasonic ");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print(distance);
      Serial.println(" cm");
      j++;
      
      //noTone(buzzer);
    }
    //delay(500);
  }
  g_im.send_numdata(TAG_ID, (int)j);
  j=0;

  //uji coba
  /*
    digitalWrite(ultra2, 1);
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
      //tone(buzzer, 500);
      //delay(1000);
    }
    else
    {
      Serial.print(distance);
      Serial.println(" cm");
      //noTone(buzzer);
    }
    delay(400);
  */

  //g_im.loop();
}
