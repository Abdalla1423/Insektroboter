
class Ultraschallsensor {

  private:
    int trig;
    int echo;

  public:
    Ultraschallsensor(int trig, int echo): trig(trig), echo(echo) {}
    
  int getDistance () {
    digitalWrite(trig, LOW); //Startzustand setzen, um Rauschen zu verhindern
    delayMicroseconds(1);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    //wartet 250µs, dann echo zu high
    int duration = pulseIn(echo, HIGH, 200000); //misst Zeit bis Signal an echo zurückkommt; Abbruch nach 200msec, wenn nichts zurückkommt
    return (duration / 2) * 340 * 0.0001;
  }
};

Ultraschallsensor uSensor1(6, 7);
Ultraschallsensor uSensor2(8, 3);

void Kantenerkennung()
{
  int distance1 = uSensor1.getDistance();
  int distance2 = uSensor2.getDistance();
 
  if (distance1 >= 6) {
    stoppen();
    PiezoKante(50);
    delay(10);
    linksDrehen(90);
  }

  if (distance2 >= 6) {
    stoppen();
    PiezoKante(50);
    delay(10);
    rechtsDrehen(90);
  }
}

void Objekterkennung() {
  float distanceObj1 = averageDistance(sensor1);;
  float distanceObj2 = averageDistance(sensor2);;
  float distanceObj3 = averageDistance(sensor3);;

  //Distanz von Hindernis zu mittlerem Sensor unter 25cm
   if (distanceObj1 <= 25 && distanceObj1 != 0) {
    stoppen();
    delay(10);
    rechtsDrehen(70);
  }
  
  //Distanz von Hindernis zu rechtemSensor unter 25cm
   if (distanceObj2 <= 20 && distanceObj2 != 0) {
    stoppen();
    delay(10);
    linksDrehen(70);
  }

  //Distanz von Hindernis zu linkem Sensor unter 25cm
   if (distanceObj3 <= 20 && distanceObj3 != 0) {
    stoppen();
    delay(10);
    rechtsDrehen(70);
  }
}

//Durchschnittsdistanz aus 10 Messwerten, um Fehlmessungen zu filtern
float averageDistance(int sensor) {

  float sum;
  for (int i = 0; i<10; i++) {
    sum = sum + pow(3027.4 / analogRead(sensor), 1.2134);
  }
  return sum / 10;
}
