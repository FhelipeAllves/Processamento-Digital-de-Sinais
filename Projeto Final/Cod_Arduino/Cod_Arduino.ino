// Pinos configurados
const int adcPin = 34;     // Pino de entrada analógica (ADC1_CH6)
const int dacPin = 25;     // Pino de saída analógica (DAC1)
float xn1 = 0;
float yn1 = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Resolução de 0–4095 (12 bits)
  analogSetAttenuation(ADC_11db);  // Para medir até ~3.3V
}

void loop() {
  int adcValue = analogRead(adcPin);   // Lê valor analógico (0-4095)

  //float t = micros()/1.0e6;
  //float adcValue = sin(2*PI*60*t) + 2*sin(2*PI*5*60*t);
  //int xn = (adcValue + 1.5)*255 / 3;
  
  int xn = map(adcValue, 0, 4095, 0, 255);  // Ajusta para escala do DAC (8 bits)
  
  float yn = 0.598*yn1 + 0.201*xn + 0.201*xn1;

  delay(1);
  xn1 = xn;
  yn1 = yn;

  dacWrite(dacPin, yn);   // Escreve valor no DAC
}
