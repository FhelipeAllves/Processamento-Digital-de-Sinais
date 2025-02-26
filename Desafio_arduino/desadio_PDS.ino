float valor_V;
unsigned int valor_ad;
 
void setup() {
Serial.begin(9600);
}

void loop() {

  valor_ad = analogRead(A0);
  valor_V = (valor_ad*5)/1023;
  Serial.println(valor_V);
  
  int valor_pwm = map(valor_ad, 0, 1023, 0, 255);  // Converte para escala de PWM (0-255)
  
  analogWrite(3, valor_pwm);  // Escreve o PWM no pino D3

  delay(1000);

}
