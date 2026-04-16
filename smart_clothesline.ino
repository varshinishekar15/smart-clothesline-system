#include <Servo.h>

Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin = 5;
int led_pin = 3;
int led1 = 2;
int val1 = 0;
int inputP1 = 8;
int val;

void setup() {
  Serial.begin(9600);

  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(inputP1, INPUT);

  tap_servo.attach(tap_servo_pin);
}

void loop() {
  val = digitalRead(sensor_pin);

  if (val == 1) {
    tap_servo.write(0);
  } else {
    tap_servo.write(180);
  }

  int value = analogRead(A0);
  Serial.print("Value : ");
  Serial.println(value);

  if (value < 900) {
    digitalWrite(led_pin, HIGH);
    Serial.println("It is raining");
  } else {
    digitalWrite(led_pin, LOW);
  }

  val1 = digitalRead(inputP1);

  if (val1 == HIGH) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  delay(1000);
}
