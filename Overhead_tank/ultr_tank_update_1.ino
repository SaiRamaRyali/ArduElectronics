#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);

#define triggerpin 10
#define echopin 11
unsigned int val;
long duration;
unsigned int q;
void setup()
{
Serial.begin(9600);
mySerial.begin(115200);
pinMode(triggerpin,OUTPUT);
pinMode(echopin,INPUT);
}

void loop(){
  val= val_measure();
  //Serial.println("val at starting of loop is :" );
  //Serial.print(val);
  q= map(val,0,100,10,100);
 
  if(q<100){    
  mySerial.print(q);
 
  }else{}
 // Serial.println(q);
  delay(100);
  
   Serial.println(q);
 }

int val_measure(){
  
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


long microTocenti(long microseconds)
{
int x=microseconds/29/2;
return x;
}

