void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
}

void getNumber(int pincodes[], int arraySize, int state) {
  if (state == 0) { 
    for (int i = 0; i < arraySize; i++) {
      digitalWrite(pincodes[i], LOW);
    }  
  }
  
  if (state == 1) {
    for (int i = 0; i < arraySize; i++) {
      digitalWrite(pincodes[i], HIGH);
    }
  }


}

int number = 0;

//void turnOnOff(,state) {
//
//}

void loop() {
  int pincodes0[] = {13, 12, 11, 10, 9, 8};
  int pincodes1[] = {12, 11};
  int pincodes2[] = {13, 12, 10, 7, 9};
  int pincodes3[] = {13, 12, 7, 11, 10};
  int pincodes4[] = {8, 7, 12, 11};
  int pincodes5[] = {13, 8, 7, 11, 10};
  int pincodes6[] = {8, 7, 9, 10, 11, 13};
  int pincodes7[] = {13, 12, 11};
  int pincodes8[] = {13, 8, 12, 7, 9, 10, 11};
  int pincodes9[] = {13, 8, 12, 7, 11};

  if (digitalRead(2)) {
    switch (number) {
      case 0:
        getNumber(pincodes9, 5, 0);
        getNumber(pincodes0, 6, 1);
        number++;
        break;
      case 1:
        getNumber(pincodes0, 6, 0);
        getNumber(pincodes1, 2, 1);
        number++;
        break;
      case 2:
        getNumber(pincodes1, 2, 0);
        getNumber(pincodes2, 5, 1);
        number++;
        break;
      case 3:
        getNumber(pincodes2, 5, 0);
        getNumber(pincodes3, 5, 1);
        number++;
        break;
      case 4:
        getNumber(pincodes3, 5, 0);
        getNumber(pincodes4, 4, 1);
        number++;
        break;
      case 5:
        getNumber(pincodes4, 4, 0);
        getNumber(pincodes5, 5, 1);
        number++;
        break;
      case 6:
        getNumber(pincodes5, 5, 0);
        getNumber(pincodes6, 6, 1);
        number++;
        break;
      case 7:
        getNumber(pincodes6, 6, 0);
        getNumber(pincodes7, 3, 1);
        number++;
        break;
      case 8:
        getNumber(pincodes7, 3, 0);
        getNumber(pincodes8, 7, 1);
        number++;
        break;
      case 9:
        getNumber(pincodes8, 7, 0);
        getNumber(pincodes9, 5, 1);
        number = 0;
        break;
    }
    while (digitalRead(2)) delay(15);
    

    
  }
}
