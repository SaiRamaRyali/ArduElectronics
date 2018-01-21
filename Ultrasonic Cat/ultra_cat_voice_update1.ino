

#include <Servo.h>
#define triggerpin 10
#define echopin 11
Servo servo;
int l2=2,l7=7,l10=12,l15=13;
int play=4;
int val;  
//int val_measure();
long duration;

void setup()
{
Serial.begin(9600);
pinMode(triggerpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(l2,OUTPUT);
pinMode(l7,OUTPUT);
pinMode(l10,OUTPUT);
pinMode(l15,OUTPUT);
pinMode(play,OUTPUT);
 servo.attach(9);
 servo.write(90);
}

void loop()
{
  val= val_measure();
  Serial.println("val at starting of loop is :" );
  Serial.print(val);
  if(val>25){
  moveforward();
 }
 else{
    robotstop();
    digitalWrite(play,HIGH);
    Serial.println("playing meaawoww");
    delay(5000);
    servo.write(0);
 delay(500);
 int q = val_measure();
 Serial.println("q value is :");
 Serial.print(q);
 servo.write(179);
 delay(500);
 int r= val_measure();
 Serial.println("r value is :");
 Serial.print(r); 
  servo.write(90);
   digitalWrite(play,LOW);
    delay(500);
 
 if((q-r)>0){
   moveleft();
   delay(1000);
 }
else{
 moveright();
 delay(1000);
}
}}
  
int val_measure()
{
digitalWrite(triggerpin,LOW);
delayMicroseconds(2);
digitalWrite(triggerpin,HIGH);
delayMicroseconds(10);
digitalWrite(triggerpin,LOW);
delayMicroseconds(2);

duration=pulseIn(echopin,HIGH);
int p=microTocenti(duration);
return p;
Serial.println(p);
}

void moveforward()
{
   Serial.println("moving forward");
   digitalWrite(l2,LOW);
   digitalWrite(l7,HIGH);
   digitalWrite(l10,HIGH);
   digitalWrite(l15,LOW);
}


void moveright()
{
   Serial.println("moving right");
   digitalWrite(l2,HIGH);
   digitalWrite(l7,LOW);
   digitalWrite(l10,HIGH);
   digitalWrite(l15,LOW);
}

void moveleft()
{
   Serial.println("moving left");
   digitalWrite(l2,LOW);
   digitalWrite(l7,HIGH);
   digitalWrite(l10,LOW);
   digitalWrite(l15,HIGH);
}

void robotstop()
{
   Serial.println("robot stoped");
   digitalWrite(l2,LOW);
   digitalWrite(l7,LOW);
   digitalWrite(l10,LOW); 
   digitalWrite(l15,LOW);
}


long microTocenti(long microseconds)
{
int x=microseconds/29/2;
return x;
}

