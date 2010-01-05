#include <WProgram.h>

void boot()
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
