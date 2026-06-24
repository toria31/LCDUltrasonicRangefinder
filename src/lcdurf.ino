#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// define variables
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distanceCm;

void setup() {
  lcd.begin(16, 2); // initialzes the interface to the lcd screen and specifies width and height of the display
  // configure trig and echo pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop() {
  // turn trig pin periodically
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // calculate distance (S = T * V ) 
  // NOTE. formula is explained in README file
  distanceCm = duration * 0.034 / 2;

  lcd.setCursor(0, 0); // set lcd cursor on 0, 0 coords.
  // display Distance
  lcd.print("Distance: "); 
  lcd.print(distanceCm);
  lcd.print(" cm ");
}
