
void lichterkennung()
{
  int schwellwert = 50;

  //Licht am linken Sensor
  if(analogRead(Ph1)- analogRead(Ph2) > schwellwert)
  {
    linksDrehen(20);
  }

  //Licht am rechten Sensor
  else if(analogRead(Ph2)- analogRead(Ph1) > schwellwert)
  {
    rechtsDrehen(20);
  }

  //Licht von hinten
  else if(analogRead(Ph3)- analogRead(Ph1) > schwellwert  && analogRead(Ph3)- analogRead(Ph2) > schwellwert)
  {
    linksDrehen(150);
  }

}
