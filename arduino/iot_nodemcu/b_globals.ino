#include <WiFiClient.h>

float humidity, temp_c; // Values read from sensor
bool r1, r2; // State from relays

IPAddress ip;
long rssi;
int rssi_per;

String toString(float value) {
  char buffer[10];
  dtostrf(value,3,1,buffer);
  return buffer;
}
