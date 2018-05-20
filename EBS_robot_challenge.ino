#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h>

#define PWM_READ_PIN 7
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *myStepper = AFMS.getStepper(513, 2);  // to motor port #2 (M3 and M4)
Servo myservo;


unsigned long duration;

int degree;
int usec;
void setup() {
  pinMode(PWM_READ_PIN, INPUT);
  Serial.begin(115200);
  AFMS.begin();  // create with the default frequency 1.6KHz

  myservo.attach(10);
  myStepper->setSpeed(20);  // 20 rpm
}


void loop() {

  duration = pulseIn(PWM_READ_PIN, HIGH);

  //  Serial.println(duration);
  //  delay(50);


  if (duration > 1500) {
    myservo.writeMicroseconds(980); // 985~2004 is 0~90 degree
    delay(200);
    myservo.writeMicroseconds(1550);
    delay(1000);
    myStepper->step(341, FORWARD, DOUBLE); //2052 step is 360 degree
    myStepper->release();
  }


}
