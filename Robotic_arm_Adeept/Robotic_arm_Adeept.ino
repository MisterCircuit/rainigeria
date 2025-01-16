
#include <Servo.h>
Servo servo1;//create servo object to control a servo
Servo servo2;//create servo object to control a servo
Servo servo3;//create servo object to control a servo
Servo servo4;//create servo object to control a servo
Servo servo5;//create servo object to control a servo


void setup()
{
  Serial.begin(9600);

  servo1.attach(9);//attachs the servo1 on pin 9 to servo object
  servo2.attach(6);//attachs the servo2 on pin 6 to servo object
  servo3.attach(5);//attachs the servo3 on pin 5 to servo object
  servo4.attach(3);//attachs the servo4 on pin 3 to servo object
  servo5.attach(11);//attachs the servo5 on pin 11 to servo object

  servo1.write(0); //goes to dataServo1 degrees
  servo2.write(180); //goes to dataServo2 degrees
  servo3.write(70); //goes to dataServo3 degrees
  servo4.write(60); //goes to dataServo4 degrees
  servo5.write(35); //goes to dataServo5 degrees
  delay (1000);
}
void loop()
{
 
  roboarm();
}

void roboarm() {
   delay(5000); //motor goes forth
  for (int i = 100; i >= 0; i -= 10) {
    servo1.write(i);
    delay(50);
  }
  servo2.write(180); //goes to dataServo2 degrees
  servo3.write(70); //goes to dataServo3 degrees
  servo4.write(60); //goes to dataServo4 degrees
  delay(2000);//wait for 0.05second
  servo5.write(35); //goes to dataServo5 degrees
  delay(8000); //motor goes back

  for (int i = 0; i <= 100; i += 10) {
    servo1.write(i);
    delay(10);
  }
  servo2.write(180); //goes to dataServo2 degrees
  servo3.write(70); //goes to dataServo3 degrees
  servo4.write(60); //goes to dataServo4 degrees
  delay(2000);//wait for 0.05second
  servo5.write(90); //goes to dataServo5 degrees
  delay(3000);//wait for 0.05second
}
