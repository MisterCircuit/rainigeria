#include <Servo.h>
Servo myservo;
#define List_Size 50
unsigned long objectQueue[List_Size];
int queueEnd=0;
int queueStart=0;
unsigned long delayTime=9000;
int statusservo = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(60);
  Serial.println("Send DETECT via serial moonitor to simulate object detection");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char signal = Serial.read(); // Read the incoming signal
Serial.println (signal);

    if (signal == '1'  && statusservo==0) {
      statusservo=1;
      add_to_list(millis());
      Serial.println("open");
add_to_list(millis());

    }
        else if ( signal=='0'  && statusservo==1) {
//      digitalWrite(ledPin, LOW); // Turn off the LED
//      myservo.write(180);
       Serial.println ("return");
      statusservo=0;
      //delay (2000);
    }
        }
processQueue();
}

void add_to_list(unsigned long detectionTime){
  int next_List_End=(queueEnd + 1)% List_Size;
  if (next_List_End!=queueStart){
    objectQueue[queueEnd]=detectionTime;
    queueEnd=next_List_End;
    }
    else{
      Serial.println("List full, skipping object");
      }
    }
 void processQueue(){
  unsigned long currentTime=millis();
  while(queueStart!=queueEnd && currentTime-objectQueue[queueStart]>= delayTime){
    triggerServo();
    queueStart=(queueStart + 1)% List_Size;
    
    }
  }
 void triggerServo(){
  Serial.println("Triggering servo");
  myservo.write(0);
  delay(200);
 myservo.write(60);
  }
