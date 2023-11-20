#define LASERPIN 7

void setup() {
  pinMode(LASERPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String inputText = Serial.readStringUntil('\n');
    int length = inputText.length();
    int ar[100];
    int m;
    int bits[8];

    for (int i = 0; i < length; i++) {
      ar[i] = int(inputText[i]);
    }

    for (int n = 0; n < length; n++) {
      m = ar[n];
      int z;
      int bin[7];
      int newbin[7];

      for (z = 0; z < 8; z++) {
        bin[z] = m % 2;
        m = m / 2;
      }

      for (int j = 7; j >= 0; j--) {
        newbin[7 - j] = bin[j];
      }

      for (int p = 0; p < 8; p++) {
        if (newbin[p] == 1) {
          bits[p] = HIGH;
        }
        if (newbin[p] == 0) {
          bits[p] = LOW;
        }
      }

      bits[0] = HIGH;

      for (int i = 0; i < 8; i++) {
        digitalWrite(LASERPIN, bits[i]);
        delay(10);
      }

      digitalWrite(LASERPIN, LOW);
      delay(100);
    }
  }
}
