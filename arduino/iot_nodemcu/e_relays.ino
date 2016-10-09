#define R1PIN D5
#define R2PIN D6

void toggleR1(bool high) {
  if (high) {
    digitalWrite(R1PIN, LOW);
    r1 = true;
  }
  else {
    digitalWrite(R1PIN, HIGH);
    r1 = false;
  }

  updateLCDState();
}

void toggleR2(bool high) {
  if (high) {
    digitalWrite(R2PIN, LOW);
    r2 = true;
  }
  else {
    digitalWrite(R2PIN, HIGH);
    r2 = false;
  }

  updateLCDState();
}

void setupRelays() {
  pinMode(R1PIN, OUTPUT);
  pinMode(R2PIN, OUTPUT);

  toggleR1(false);
  toggleR2(false);
}
