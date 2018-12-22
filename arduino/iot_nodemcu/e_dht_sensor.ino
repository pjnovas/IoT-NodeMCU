#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN  D2 // Pin for Sensor

DHT dht(DHTPIN, DHTTYPE, 11);

unsigned long dht_previousMillis = 0;       // will store last temp was read

void read_temperature() {
  float _humidity, _temp_c, _hi_c;
  unsigned long currentMillis = millis();

  if(currentMillis - dht_previousMillis >= globalConfig.refreshRate) {
    dht_previousMillis = currentMillis;

    _humidity = dht.readHumidity();
    _temp_c = dht.readTemperature();

    if (isnan(_humidity) || isnan(_temp_c)) {
      #ifdef DEBUG
        Serial.println("Failed to read from DHT sensor!");
      #endif
      return;
    }

    humidity = _humidity;
    temp_c = _temp_c;

    updateLCDState();

    #ifdef DEBUG
      Serial.println("READ DHT sensor OK!");
    #endif
  }
}

void setupSensor() {
  dht.begin();
}

void loopSensor() {
  read_temperature();
}
