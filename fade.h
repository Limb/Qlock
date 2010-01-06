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
