
void linienerkennung()
{
  //Richtungskorrektur, um auf Linie zu bleiben
  if (digitalRead(lsLinks) == HIGH && digitalRead(lsRechts) == LOW)
  {
    linksDrehen(5);
  }

  else if (digitalRead(lsLinks) == LOW && digitalRead(lsRechts) == HIGH )
  {
    rechtsDrehen(5);
  }

  //Positionierung auf neu entdeckter Linie
  else if (digitalRead(lsLinks) == HIGH  && digitalRead(lsRechts) == HIGH )
  {
    geradeausFahren();
    delay(50);
    stoppen();
    rechtsDrehen(90);
  }
}
