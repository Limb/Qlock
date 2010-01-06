#include <WProgram.h>
#include "fade.h"

void clockBoot()
{
  for(int a = 0; a <= 4095; a += 35)
  {
    Tlc.setAll(a);
    Tlc.update();
    delay(25);
  }
  delay(1000);
  for(int a = 4095; a >= 0; a -= 35)
  {
    Tlc.setAll(a);
    Tlc.update();
    delay(15);
  }
}

void clockSet(byte hour, byte min, byte sec)
{
  byte pinHour = 0;
  byte mins = min%5;
  
  Tlc.setAll(0);
  
  if(hour > 12)
  {
    hour -= 12;
    pinHour = hour + 16;
  }
  else
    pinHour = hour + 16;
  
  switch((int)floor(min/5))
  {
    case 0:
    {
      byte in[] = {pinHour, pinOClock};
      fadeInBoot(in, 2, mins);
      break;
    }
    case 1:
    {
      byte in[] = {pinFiveTop, pinPast, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 2:
    {
      byte in[] = {pinTenTop, pinPast, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 3:
    {
      byte in[] = {pinA, pinQuarter, pinPast, pinHour};
      fadeInBoot(in, 4, mins);
      break;
    }
    case 4:
    {
      byte in[] = {pinTwenty, pinPast, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 5:
    {
      byte in[] = {pinTwenty, pinFiveTop, pinPast, pinHour};
      fadeInBoot(in, 4, mins);
      break;
    }
    case 6:
    {
      byte in[] = {pinHalf, pinPast, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 7:
    {
      byte in[] = {pinTwenty, pinFiveTop, pinTo, pinHour};
      fadeInBoot(in, 4, mins);
      break;
    }
    case 8:
    {
      byte in[] = {pinTwenty, pinTo, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 9:
    {
      byte in[] = {pinA, pinQuarter, pinTo, pinHour};
      fadeInBoot(in, 4, mins);
      break;
    }
    case 10:
    {
      byte in[] = {pinTenTop, pinTo, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    case 11:
    {
      byte in[] = {pinFiveTop, pinTo, pinHour};
      fadeInBoot(in, 3, mins);
      break;
    }
    default:
      break;
  }

}

void clockUpdate(byte hour, byte min, byte sec)
{
  Tlc.update();
}
