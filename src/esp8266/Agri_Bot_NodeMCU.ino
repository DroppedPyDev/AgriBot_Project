#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include <Servo.h>

// ============================================================
// Agri_Bot NodeMCU
// ESP8266-based IoT Agricultural Robot
// ============================================================
// SECURITY: Never commit real Blynk tokens or Wi-Fi passwords.
// Use the placeholders below or provide them through a private
// local configuration before uploading the sketch.
// ============================================================

#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

Servo servo;
Servo servo1;

// Original report mapping
#define DPIN D6
#define DTYPE DHT22   // Verify the physical sensor model: DHT11/DHT22.
DHT dht(DPIN, DTYPE);

// Motor-control pins from the original sketch
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;

// Auxiliary outputs from the original sketch
const int cutterPin = D8;
const int pumpPin = 10; // Original sketch used GPIO10; verify wiring before use.

int motorSpeed = 10;

// ------------------------------------------------------------
// Servo control from Blynk virtual pin V4
// ------------------------------------------------------------
BLYNK_WRITE(V4)
{
  Serial.println("servo angle: ");
  Serial.println(param.asInt());

  servo.write(param.asInt());

  if (param.asInt() > 130) {
    servo1.write(0);
  } else {
    servo1.write(180);
  }
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  pinMode(cutterPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);

  pinMode(pwmMotorA, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorB, OUTPUT);

  servo.attach(D7);
  servo.write(0);

  servo1.attach(D5);
  servo1.write(0);

  // Original active-HIGH initialization
  digitalWrite(cutterPin, HIGH);
  digitalWrite(pumpPin, HIGH);
}

void loop()
{
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case 'F':
        analogWrite(pwmMotorA, motorSpeed);
        digitalWrite(dirMotorA, HIGH);
        analogWrite(pwmMotorB, motorSpeed);
        digitalWrite(dirMotorB, LOW);
        Serial.println("forward");
        break;

      case 'B':
        analogWrite(pwmMotorA, motorSpeed);
        digitalWrite(dirMotorA, LOW);
        analogWrite(pwmMotorB, motorSpeed);
        digitalWrite(dirMotorB, HIGH);
        Serial.println("backwards");
        break;

      case 'L':
        analogWrite(pwmMotorA, motorSpeed);
        digitalWrite(dirMotorA, HIGH);
        analogWrite(pwmMotorB, motorSpeed);
        digitalWrite(dirMotorB, HIGH);
        Serial.println("left");
        break;

      case 'R':
        analogWrite(pwmMotorA, motorSpeed);
        digitalWrite(dirMotorA, LOW);
        analogWrite(pwmMotorB, motorSpeed);
        digitalWrite(dirMotorB, LOW);
        Serial.println("right");
        break;

      case 'S':
        analogWrite(pwmMotorA, 0);
        digitalWrite(dirMotorA, LOW);
        analogWrite(pwmMotorB, 0);
        digitalWrite(dirMotorB, LOW);
        Serial.println("stop");
        break;

      case 'Y':
        digitalWrite(cutterPin, LOW);
        Serial.println("cutter off");
        break;

      case 'X':
        digitalWrite(cutterPin, HIGH);
        Serial.println("cutter on");
        break;

      case 'N':
        digitalWrite(pumpPin, LOW);
        Serial.println("pump off");
        break;

      case 'M':
        digitalWrite(pumpPin, HIGH);
        Serial.println("pump on");
        break;
    }
  }

  DHT11sensor();
  soilMoistureSensor();
  Blynk.run();
}

void soilMoistureSensor()
{
  int analogSensor = analogRead(A0);
  int value = analogSensor;

  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V1, value);
}

void DHT11sensor()
{
  float tc = dht.readTemperature(false);
  float hu = dht.readHumidity();

  Blynk.virtualWrite(V2, tc);
  Blynk.virtualWrite(V3, hu);
}
