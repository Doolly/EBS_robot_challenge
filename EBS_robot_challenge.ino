
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myStepper = AFMS.getStepper(513, 2);

Servo myservo;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("MMMMotor party!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Attach a servo to pin #10
  myservo.attach(10);

  myStepper->setSpeed(20);  // 20 rpm   
}

int i;
void loop() {

for ( i=1000; i<1500; i++) {
    myservo.writeMicroseconds(i);
    delay(1);
}
for (i = 1500; i >= 1000; i -= 1) { // goes from 180 degrees to 0 degrees
    myservo.writeMicroseconds(i);              // tell servo to go to position in variable 'pos'
    delay(1);      
}


    myStepper->step(341, FORWARD, DOUBLE);
    delay(1000);
    myStepper->release();
    delay(3000);
    

}
