#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

#define LIGHT A3
#define LED A5
#define Buzzer 6
#define deviceID "hendraD1566883504165"
#define authnRqtNo "zcl5chgqp"
#define extrSysID "OPEN_TCP_001PTL001_1000007610"

#define WIFI_SSID "ICT-LAB-2.4G"
#define WIFI_PASS "12345678"
#define TAG_ID "light"

IoTMakers g_im;
int value;
int data;

void init_iotmakers()
{
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
  
    Serial.print(F("Auth..."));
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}

void setup() {
  Serial.begin(9600);
  init_iotmakers();
  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() 
{
 
  static unsigned long tick = millis();

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

  if((millis() - tick) > 5000)
  {
    lampu();
    tick = millis();
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

  g_im.loop();
}

void lampu()
{
  value = analogRead(LIGHT);
  data = map(value, 0, 1023, 0, 255);
  if(g_im.send_numdata(TAG_ID, (double)value) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }

  return 0;
  
  
  
}
