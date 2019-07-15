/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
#include <Servo.h>
// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;

// defines variables
long duration;
int distance;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(13, OUTPUT);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Starts the serial communication
  pinMode(A0,OUTPUT);
  pinMode(A3,OUTPUT);
  digitalWrite(A0,LOW);
  digitalWrite(A3,LOW);
}
void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(10);// waits 15ms for the servo to reach the position
    Ultrasonic();
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(10);                       // waits 15ms for the servo to reach the position
    Ultrasonic();
  }
}

void Ultrasonic(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 20) {
    Serial.println("detected");
    digitalWrite(13, HIGH);
    digitalWrite(A0,HIGH);
  }
  else {
    digitalWrite(13, LOW);
    digitalWrite(A0,LOW);
  }
}
