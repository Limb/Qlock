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
  Tlc.setAll(0);
  if(hour > 12)
  {
    hour -= 12;
  }
  fadeIn(hour + 16);
}

void clockUpdate(byte hour, byte min, byte sec)
{
  if(hour > 12)
    hour -= 12;
  if(min == 0 && sec == 0)
  {
    if(hour == 0)
    {
      fadeHours(pinEleven, pinTwelve);
    }
    else
      fadeHours((hour + 15), (hour + 16));
  }
  Tlc.update();
}
