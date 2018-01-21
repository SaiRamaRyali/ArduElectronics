#include<SoftwareSerial.h>
const int led1 =  13;
const int led2 =  12;
const int led3 =  6;
const int led4 =  5;
SoftwareSerial mySerial(10,11);

void setup()
{
 pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(57600);
  Serial.println("bluetooth controlled home appliances");
}

void loop()
{
 int c; 
  if(mySerial.available())
 {
    c=mySerial.read();
     if(c=='a')
     {
         digitalWrite(led1,HIGH);
         Serial.println("led1 status on");
       }
      if(c=='b')
     {
         digitalWrite(led1,LOW);
         Serial.println("led1 status off");
         }
       
       if(c=='d')
       {
         digitalWrite(led2,HIGH);
         Serial.println("led2 status on");
       }
       
        if(c=='e') 
        {
          digitalWrite(led2,LOW);
         Serial.println("led2 status off");
        }
        
         if(c=='f') 
        {
          digitalWrite(led3,HIGH);
         Serial.println("led3 status on");
        }
        
         if(c=='g') 
        {
          digitalWrite(led3,LOW);
         Serial.println("led3 status off");
        }
        
         if(c=='h') 
        {
          digitalWrite(led4,HIGH);
         Serial.println("led4 status on");
        }
        
         if(c=='i') 
        {
          digitalWrite(led4,LOW);
         Serial.println("led4 status off");
        }

 }
} 
  
