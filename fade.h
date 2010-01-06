void fadeInBoot(byte in[], int size, byte mins)
{
  for(int a = 0; a <= 4095; a += 35)
  {
    Tlc.set(pinItIs, a);
    for(int n = 0; n < size; n++)
      Tlc.set(in[n], a);
    for(int n = 0; n < mins; n++)
      Tlc.set(n, a);
    Tlc.update();
    delay(15);
  }
}

void fadeInOut(byte in[], int sizeIn, byte out[], byte sizeOut)
{
  int b = 4095;
  for(int a = 0; a <= 4095; a += 35)
  {
    Tlc.set(pinItIs, a);
    for(int n = 0; n < sizeIn; n++)
      Tlc.set(in[n], a);
    for(int n = 0; n < sizeOut; n++)
      Tlc.set(out[n], b);
    Tlc.set(pinMin1, b);
    Tlc.set(pinMin2, b);
    Tlc.set(pinMin3, b);
    Tlc.set(pinMin4, b);
    Tlc.update();
    b -= 35;
    delay(15);
  }
}


void fadeIn(byte in)
{
  for(int a = 0; a <= 4095; a += 35)
  {
    Tlc.set(in, a);
    Tlc.update();
    delay(15);
  }
}

void fadeOut(byte out)
{
  for(int a = 4095; a >= 0; a -= 35)
  {
    Tlc.set(out, a);
    Tlc.update();
    delay(15);
  }
}
