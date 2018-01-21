#include<SoftwareSerial.h>
int led1 =11;
int c;
SoftwareSerial mySerial(9,10);
void setup()
{
 pinMode(led1,OUTPUT);
  Serial.begin(1200);
  mySerial.begin(57600);
  Serial.println("bluetooth controlled home appliances");
}
void loop()
{ 
  if(mySerial.available())
 {
   c=mySerial.read();
    Serial.print("value received is :     ");
    Serial.println(c);
   int p=map(c,0,255,0,255);
    Serial.print("value mapped is :    ");
    Serial.println(p);   
    analogWrite(led1,p);
 }
  else{
  Serial.println("no available data found");
  }

}

     
     
 
 
  
