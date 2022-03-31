
float gyroAngle();


void geradeausFahren() {
  digitalWrite(richtung1, LOW);
  digitalWrite(richtung2, LOW);
  analogWrite(basis1, pwm1);
  analogWrite(basis2, pwm1);
}

void rueckwaertsFahren() {
  digitalWrite(richtung1, HIGH);
  digitalWrite(richtung2, HIGH);
  analogWrite(basis1, pwm1 - 255);
  analogWrite(basis2, pwm1 - 255);
}

void schlangenlinienFahren() {
  digitalWrite(richtung1, HIGH);
  digitalWrite(richtung2, HIGH);
  analogWrite(basis1, pwm1 - 10);
  analogWrite(basis2, pwm2);
  delay(1000);

  analogWrite(basis1, pwm2 - 10);
  analogWrite(basis2, pwm2);
  delay(500);

  analogWrite(basis1, pwm2 - 10);
  analogWrite(basis2, pwm1);
  delay(1000);
}

void rechtsDrehen(int drehwinkel) {
  int richtungVorher = gyroAngle();
  digitalWrite(richtung1, LOW);
  digitalWrite(richtung2, HIGH);
  while ( gyroAngle() <= richtungVorher + drehwinkel) {
    analogWrite(basis1, pwm1);
    analogWrite(basis2, 255 - pwm1);
  }
stoppen();
}

void linksDrehen(int drehwinkel) {
  int richtungVorher = gyroAngle();
  digitalWrite(richtung1,HIGH );
  digitalWrite(richtung2, LOW);
  while (gyroAngle() >= richtungVorher - drehwinkel) {
    analogWrite(basis2, pwm1);
    analogWrite(basis1, 255 - pwm1);
  }
  stoppen();
}

void stoppen() {
  digitalWrite(richtung1, LOW);
  digitalWrite(richtung2, LOW);
  analogWrite(basis1, 0);
  analogWrite(basis2, 0);
}
