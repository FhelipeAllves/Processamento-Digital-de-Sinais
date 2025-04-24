///////////////////////////////////////////////////////////////////////////////////
/////////////////// Autor: Luiz Felipe Barros Alves ///////////////////////////////
//////////////// Implementação de um Filtro Butterworth  //////////////////////////
/////////////////////// passa-baixa de segunda ordem //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


// Pinos configurados
const int adcPin = 34;  // Pino de entrada analógica (ADC1_CH6)
const int dacPin = 25;  // Pino de saída analógica (DAC1)
float x[] = {0,0,0};    // Vetor para guardar os valores da entrada 
float y[] = {0,0,0};    // Vetor para guardar os valores da saída 
int xn = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Resolução de 0–4095 (12 bits)
  analogSetAttenuation(ADC_11db);  // Para medir até ~3.3V
}

void loop() {
  int adcValue = analogRead(adcPin);   // Lê valor analógico (0-4095)

  // Sinal interno gerado para teste
  //float t = micros()/1.0e6;
  //float adcValue = sin(2*PI*60*t) + 2*sin(2*PI*5*60*t);
  //int xn = (adcValue + 1.5)*255 / 3;
  
  float xn = map(adcValue, 0, 4095, 0, 255);  // Ajusta para escala do DAC (8 bits)

  float b[] = {0.04452675, 0.08905349, 0.04452675}; // Coeficientes do numerador
  float a[] = {1.32079107 -0.49889805};             // Coeficientes do denominador
  
  y[0] = a[0]*y[1] + a[1]*y[2] + b[0]*xn+ b[1]*x[1] + b[2]*x[2];

  delay(1);
  // Atualização do dados salvo na memória
  y[2] = y[1];
  y[1] = y[0];

  x[2] = x[1];
  x[1] = xn;

  dacWrite(dacPin, y[0]);   // Escreve valor no DAC
}
