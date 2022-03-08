#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd( 7, 6, 4, 3, 2, 1);

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;

Servo myservo;
int pos = 0;

void setup() {
  lcd.begin(16,2);
  myservo.attach(8);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
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
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 10){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  pos=90;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  pos=0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distance); // Prints the distance value from the sensor
lcd.print("  cm");
delay(10);




}
