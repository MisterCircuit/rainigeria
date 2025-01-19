int ledPin = 13; // Pin connected to the LED
int statusservo = 0;
#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(9);
  myservo.write(180);
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read(); // Read the incoming signal
    Serial.println (signal);
    if (signal == '1'  && statusservo==0) {
      statusservo=1;
      delay(9000);
      Serial.println("open");
      digitalWrite(ledPin, HIGH); // Turn on the LED
      myservo.write(0);
      delay(2000);
    } 
    else if ( signal=='0'  && statusservo==1) {
      digitalWrite(ledPin, LOW); // Turn off the LED
      myservo.write(180);
       Serial.println ("return");
      statusservo=0;
      //delay (2000);
    }
  }
}
