void setup() {
  // initialize the LED pin as an output:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

int currentLed = 13;
int click = 0;

void loop() {
  Serial.println(currentLed);
  if (digitalRead(2)) {
    digitalWrite(currentLed, 1);
    while (digitalRead(2)) delay(10);
    digitalWrite(currentLed, 0);
    if (currentLed == 7) {
      currentLed = 13;
    } else {
      --currentLed;
    }
  }
}
