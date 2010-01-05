/*
Qlock Two Remake by Kenneth Lorthioir
*/

#include <Tlc5940.h>
#include <DateTime.h>
#include <Messenger.h>
#include "defines.h"
#include "clock.h"
#include "testfunctions.h"

Messenger message = Messenger();

char cMessage[25] ="";
bool moo = 0;

void messageReady()
{
  while(message.available())
  {
    if(message.checkString("set"))
    {
      long int pcTime = 0;
      pcTime = message.readLong();
      DateTime.sync((time_t)pcTime);
      Serial.println(DateTime.now(), DEC);
      Serial.println(pcTime, DEC);
    }
    if(message.checkString("get"))
    {
      Serial.print("Current Time: ");
      DateTime.available();
      Serial.print(DateTime.Hour, DEC);
      Serial.print(":");
      Serial.print(DateTime.Minute, DEC);
      Serial.print(":");
      Serial.println(DateTime.Second, DEC);
      Serial.println(DateTime.now(), DEC);
    }
    if(message.checkString("pin"))
    {
      if(message.checkString("on")) 
      {
        Tlc.setAll(4095);
        Tlc.update();
      }
      else if(message.checkString("off"))
      {
        Tlc.setAll(0);
        Tlc.update();
      }
      else 
      {
        Tlc.set(message.readInt(), message.readInt());
        Tlc.update();
      }
    }
    Serial.println(message.readChar());
  }
}

void setup() 
{
  Serial.begin(9600);
  message.attach(messageReady);
  Tlc.init();
  boot();
}

void loop() {
  while ( Serial.available() )  message.process(Serial.read () );
  
  if(moo == 0)
  {
    testTLC1();
    moo = 1;
  }
  
  Tlc.update();
}
