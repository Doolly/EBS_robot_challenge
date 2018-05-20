#define PWM_READ_PIN 7
#define PUMP_PIN 9


unsigned long duration;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(PWM_READ_PIN, INPUT);
}


void loop() {
  duration = pulseIn(PWM_READ_PIN, HIGH);
  Serial.print("duration = ");
  Serial.println(duration);

  if (duration > 1700) {
    digitalWrite(PUMP_PIN, HIGH);
  }
  else {
    digitalWrite(PUMP_PIN, LOW);
  }
}
