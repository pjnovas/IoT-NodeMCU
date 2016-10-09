#include <ESP8266WiFi.h>
#include <WiFiClient.h>

bool wifiConnected;
unsigned long wifi_signal_previousMillis = 0;       // will store last signal was read
const long wifi_signal_interval = 30000;            // interval at which to read signal

void setPercentage() {
  rssi_per = 2 * (rssi + 100);
}

void updateWifiState() {
  rssi = WiFi.RSSI();
  setPercentage();
  updateLCDState();
}

void read_signal() {
  unsigned long currentMillis = millis();

  if(currentMillis - wifi_signal_previousMillis >= wifi_signal_interval) {
    wifi_signal_previousMillis = currentMillis;
    updateWifiState();
  }
}

void connectToWifi() {
  WiFi.begin(ssid, password);

  #ifdef DEBUG
    Serial.print("\n\r \n\rWorking to connect");
  #endif

  showText(0, 0, "connecting to", true);
  showText(0, 1, ssid, false);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
      Serial.print(".");
    #endif
  }

  wifiConnected = true;

  ip = WiFi.localIP();
  updateWifiState();

  #ifdef DEBUG
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  #endif
}

void setupWifi() {
  connectToWifi();
}

void loopWifi() {
  if (wifiConnected){
    read_signal();
  }
}
