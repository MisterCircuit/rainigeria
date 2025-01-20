int enA = 6;
int enB = 3;
int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motorcontrol();

}
void speedcontrol() {

}
void motorcontrol() {
//    analogWrite(enB, 100);
//    analogWrite(enA, 135);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in1, HIGH);  //controls motor A at the out 1 and 2
  digitalWrite(in2, LOW);
  
  Serial.println("One direction");
//  for (int i =0; i <= 255; i=i+20) {    //As the enables pin increase in voltage level, so as the motor speeed changes
//    analogWrite(enB, i);
//    analogWrite(enA, i);
//    Serial.println(i);
//    delay (200);
//  }
  delay(5000);
  digitalWrite(in3, HIGH);  //controls motor B at the out 3 and 4
  digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  Serial.println("Second direction");
//    for (int i=255; i >= 0; i=i-20) {
//    analogWrite(enB, i);
//    analogWrite(enA, i);
//    Serial.println(i);
//    delay (200);
//  }
  delay(5000);
}
void sprayercontrol() {
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(5000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
