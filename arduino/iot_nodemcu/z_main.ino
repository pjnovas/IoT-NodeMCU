
void setup() {
  #ifdef DEBUG
    Serial.begin(115200);
  #endif

  setupLCD();
  setupRelays();
  setupSensor();
  setupWifi();
  setupWebServer();
}

void loop() {
  loopWebserver();
  loopSensor();
  loopWifi();
}
