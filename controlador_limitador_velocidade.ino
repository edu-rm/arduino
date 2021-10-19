void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  
  // Motor
  pinMode(5, OUTPUT);
  
  // Botões
  pinMode(2, INPUT);
  pinMode(3, INPUT);

}

int velocidade = 0;
int pinos[7] = {13,12,11,10,9,8,7};

void loop() {
  int pot = analogRead(A0);
  int potPorcentagem = map(pot, 0, 1023, 0, 100);
  if (digitalRead(3)) {
    // Aumenta velocidade
    Serial.println("+");
    if (velocidade < 255) {
      velocidade += 51;
    }
    while(digitalRead(3)) delay(15);
  }

  if (digitalRead(2)) {
    // Diminui a velocidade
    Serial.println("-");
    if (velocidade > 0) {
      velocidade -= 51;
    }
    while(digitalRead(2)) delay(15);
  }

  int velocidadeCalculada = velocidade * ((double)potPorcentagem/100);
  analogWrite(5, velocidadeCalculada);

  for (int count = 0; count < 8; count++) {
    if (count*36.5 <= velocidadeCalculada) {
        digitalWrite(pinos[count], 1);
    } else {
        digitalWrite(pinos[count], 0);  
    }
  }

  Serial.println();
  Serial.print("|");
  int count = 0;
  int current = 0;
  for (count = 0; count < 8; count++) {
    if (count*36.5 <= velocidadeCalculada) {
      current= count;
      Serial.print("⬛");
    } else {
      Serial.print(" ");
    }
  }
  Serial.print("|");
  Serial.print(" ");
  Serial.print(current);
  Serial.print("/");
  Serial.print("6");
}
