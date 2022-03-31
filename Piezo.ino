
void PiezoKante(int maximum) {
  int timer = 0;
  while (timer <= 10) {
    tone(buzzer, random(maximum, 10 * maximum));
    delay(maximum);
    timer++;
  }
  noTone(buzzer);
}
