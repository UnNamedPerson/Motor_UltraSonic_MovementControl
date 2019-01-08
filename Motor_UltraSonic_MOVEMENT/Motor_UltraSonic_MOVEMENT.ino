//#include <NewPing.h>


int M1SpeedPin = 3; // motor 1 PWM pin (LEFT WHEEL)
int M2SpeedPin = 5; // motor 2 PWM pin (RIGHT WHEEL)

int M1cw = 6;
int M1ccw = 7; // the motor 1 direction pins

int M2cw = 2;
int M2ccw = 4; // the motor 1 direction pins


int TRIGGER_PIN1 = 8;
int ECHO_PIN1 = 9;

int TRIGGER_PIN2 = 10;
int ECHO_PIN2 = 11;

int TRIGGER_PIN3 = 12;
int ECHO_PIN3 = 13;

double duration1;
double duration2;
double duration3;

double distance1;
double distance2;
double distance3;

void setup() {
  
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN1, OUTPUT);

  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);

  pinMode(ECHO_PIN3, INPUT);
  pinMode(TRIGGER_PIN3, OUTPUT);

  pinMode(M1cw, OUTPUT);
  pinMode(M1ccw, OUTPUT);
  pinMode(M1SpeedPin, OUTPUT);

  pinMode(M2cw, OUTPUT);
  pinMode(M2ccw, OUTPUT);
  pinMode(M2SpeedPin, OUTPUT);

  Serial.begin(9600);

//  Serial.begin(115200);

}

void loop() {
  

//   Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIGGER_PIN1, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIGGER_PIN1, LOW); 
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(ECHO_PIN1, HIGH);
   
//  Serial.println(" Duration1  is: " );
//  Serial.print(duration1);


  digitalWrite(TRIGGER_PIN2, HIGH);

    delayMicroseconds(10);
    
  digitalWrite(TRIGGER_PIN2, LOW);

  duration2 = pulseIn(ECHO_PIN2, HIGH);
   
//  Serial.println(" Duration2  is: " );
//  Serial.print(duration2);

  digitalWrite(TRIGGER_PIN3, HIGH);

    delayMicroseconds(10);
    
  digitalWrite(TRIGGER_PIN3, LOW); 

  duration3 = pulseIn(ECHO_PIN3, HIGH);


//  Serial.println(" Duration3  is: " );
//  Serial.print(duration3);


  // Calculating the distance
    
   distance1 = duration1*0.034/2;
   distance2 = duration2*0.034/2;
   distance3 = duration3*0.034/2;

   if(distance1 < 20){

//    Serial.println("inside the if statment");

      if(distance3 < 20){
      analogWrite(M1SpeedPin, 200);
      analogWrite(M2SpeedPin, 220);
  
      digitalWrite(M1cw, LOW);
      digitalWrite(M1ccw, HIGH);
  
      digitalWrite(M2cw, HIGH);
      digitalWrite(M2ccw, LOW);
        
      }

      else{
        
      analogWrite(M1SpeedPin, 220);
      analogWrite(M2SpeedPin, 0);
      //writing the speed of the motor
  
      digitalWrite(M1cw, HIGH);
      digitalWrite(M1ccw, LOW);
  
      digitalWrite(M2cw, HIGH);
      digitalWrite(M2ccw, LOW);
      //deciding the directions for each motor

      }
    
   }
   else if(distance3 < 20){
        
    analogWrite(M1SpeedPin, 0);
    analogWrite(M2SpeedPin, 200);

    digitalWrite(M1cw, HIGH);
    digitalWrite(M1ccw, LOW);

    digitalWrite(M2cw, LOW);
    digitalWrite(M2ccw, HIGH);

   }
   else if (distance2 < 30){
    
    analogWrite(M1SpeedPin, 170);
    analogWrite(M2SpeedPin, 170);

    digitalWrite(M1cw, HIGH);
    digitalWrite(M1ccw, LOW);

    digitalWrite(M2cw, LOW);
    digitalWrite(M2ccw, HIGH);
   }

   
   else {

    analogWrite(M1SpeedPin, 0);
    analogWrite(M2SpeedPin, 0);
    
    digitalWrite(M1cw, LOW);
    digitalWrite(M1ccw, LOW);

    digitalWrite(M2cw, LOW);
    digitalWrite(M2ccw, LOW);
    
    }
  // Prints the distance on the Serial Monitor

  Serial.print("the Distance 1 is: " );
  Serial.println(distance1);
  
  Serial.print("the Distance 2 is: " );
  Serial.println(distance2);
  
  Serial.print("the Distance 3 is: " );
  Serial.println(distance3);

}
