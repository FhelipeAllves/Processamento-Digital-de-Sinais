const int pwmPin = 9;           // Pino digital para gerar PWM
const int period_us = 16666;    // Período de 60 Hz em microssegundos (1/60 Hz = 16.666 ms)
const int half_period = period_us / 2;  // 50% duty -> metade do período

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  digitalWrite(pwmPin, HIGH);
  delayMicroseconds(half_period);

  digitalWrite(pwmPin, LOW);
  delayMicroseconds(half_period);
}
