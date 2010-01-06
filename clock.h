#include <WProgram.h>
#include "fade.h"

void clockBoot()
{
  for(int a = 0; a <= 4095; a += 35)
  {
    Tlc.setAll(a);
    Tlc.update();
    delay(15);
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
    }
    default:
      break;
  }

}

void clockUpdate(byte hour, byte min, byte sec)
{
  Tlc.update();
}
