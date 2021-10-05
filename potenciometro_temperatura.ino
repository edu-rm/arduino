void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

float temperaturaAtual = 0, temperaturaDesejada = 0;
void loop() {
    int potenciometer = analogRead(A1);
    temperaturaAtual = (float(analogRead(A0)) * 5/1023)/0.01;
    temperaturaDesejada = ((float(potenciometer) * 5/1023)/0.01)/10;

    if (temperaturaDesejada < temperaturaAtual) {
      digitalWrite(13, 1);  
    } else {
      digitalWrite(13, 0);  
    }
    
    Serial.print("CURRENT: ");
    Serial.print(temperaturaAtual);
    Serial.print(" ---- TARGET: ");
    Serial.print(temperaturaDesejada);
    Serial.println();

}
