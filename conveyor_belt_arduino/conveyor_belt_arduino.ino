#include <Servo.h>
Servo myservo; 
#define List_Size 50  // Array size
unsigned long objectQueue[List_Size]; //For storing object detected
int queueEnd=0; //
int queueStart=0;
unsigned long delayTime=9000;
int statusservo = 0; //servo status


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(60); //initial close 
  Serial.println("Send DETECT via serial moonitor to simulate object detection");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char signal = Serial.read(); // Read the incoming signal
Serial.println (signal);  //print signal received
    if (signal == '1'  && statusservo==0) {
      statusservo=1;  //prevent receiving 1 multiple times
      add_to_list(millis()); //add time it received the signal
      Serial.println("open");
    }
        else if ( signal=='0'  && statusservo==1) {
       Serial.println ("return");
      statusservo=0; //if zero received reset servo status
      }
        }
processQueue();  //function to process the list
}

void add_to_list(unsigned long detectionTime){
  int next_List_End=(queueEnd + 1)% List_Size; // take the modulo and create list end for the next
  if (next_List_End!=queueStart){
    objectQueue[queueEnd]=detectionTime;  //add detection time to array
    queueEnd=next_List_End;
    }
    else{
      Serial.println("List full, skipping object");  //if next list end and queue start is not equal
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
