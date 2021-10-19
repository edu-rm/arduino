
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int luz = 0;
int led;
void loop() {
  // put your main code here, to run repeatedly:
  luz = analogRead(A1);
  int potenciometer = analogRead(A2);
//  led = map(luz, 20, 800, 255, 0); // regra de 3
  int potConverted = map(potenciometer, 0, 1023, 20, 800); // regra de 3

  Serial.println(potConverted);
  if (luz > potConverted) {
    digitalWrite(13, 1);
  } else {
    digitalWrite(13, 0);
  }
//  analogWrite(11, led);
}
