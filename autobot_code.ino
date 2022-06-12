int w=0,b=1;
int ml1 = 2;
int ml2 = 4;
int mr1 = 6;
int mr2 = 7;
int enA = 3;
int enB = 5;
int s1=9;
int s2=10;
void setup() {
  pinMode (ml1, OUTPUT);
  pinMode (ml2, OUTPUT);
  pinMode (mr1, OUTPUT);
  pinMode (mr2, OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  Serial.begin(9600);
}
void forward()
{
  digitalWrite(ml1, HIGH);
  digitalWrite(ml2, LOW);
  digitalWrite(mr1, HIGH);
  digitalWrite(mr2, LOW);
  analogWrite(enA, 50);
  analogWrite(enB, 50);
}
void left()
{
  digitalWrite(ml1, LOW);
  digitalWrite(ml2, HIGH);
  digitalWrite(mr1, HIGH);
  digitalWrite(mr2, LOW);
  analogWrite(enA, 50);
  analogWrite(enB, 50);
}
void right()
{
  digitalWrite(ml1, HIGH);
  digitalWrite(ml2, LOW);
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, HIGH);
  analogWrite(enA, 50);
  analogWrite(enB, 50);
}
void stop1()
{
  digitalWrite(ml1, LOW);
  digitalWrite(ml2, LOW);
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void loop() {
  int sen1 = digitalRead(s1);
  int sen2 = digitalRead(s2);
   
  if (sen1 == w && sen2 == w)  {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
      forward();
      //delay(1000);
      //Serial.println("forward");
     }
  if (sen1 == b && sen2 == w)  {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    left();
    //delay(1000);
    //Serial.println("left");
  }
  if (sen1 == w && sen2 == b)  {
   analogWrite(enA, 80);
   analogWrite(enB, 80);
    right();
    //delay(1000);
    //Serial.println("right");
      }
  if (sen1 == b && sen2 == b)  {
    //delay(1000);
    //Serial.println("stop");
    stop1();
  }
}
