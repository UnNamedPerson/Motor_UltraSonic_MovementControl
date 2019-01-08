
int TRIGGER_PIN1 = 9;
int ECHO_PIN1 = 12;


double duration1;
double distance1;


void setup() {
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN1, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIGGER_PIN1, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIGGER_PIN1, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIGGER_PIN1, LOW);

  duration1 = pulseIn(ECHO_PIN1, HIGH);

  Serial.print("duration is ");
  Serial.println(duration1);

  delay(100);

//  distance1 = duration1*0.034/2;
//
//  Serial.println("Distance1"); Serial.print(distance1);

}
