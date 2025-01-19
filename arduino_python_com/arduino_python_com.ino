int x;
#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(9);
 Serial.begin(115200);
 Serial.setTimeout(1);
 myservo.write(0);
 
}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();
 myservo.write(x); 
 Serial.print(x + 1);
 if (x==1){
  digitalWrite(13, HIGH);
 }
 if (x==0){
  digitalWrite(13, LOW);
 }
}
