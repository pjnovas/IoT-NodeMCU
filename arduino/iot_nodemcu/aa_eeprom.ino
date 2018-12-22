#include <EEPROM.h>

struct EEPromGlobal { 
  int refreshRate; // interval at which to read sensor
};

EEPromGlobal globalConfig = {
  30000
};

String getEEPROMJSON() {
  return "{\"refreshRate\":" + String(globalConfig.refreshRate, 10) + "}";
}

void setupEEPROM() {
  EEPROM.begin(512);
  EEPROM.get(0, globalConfig);
  EEPROM.commit();
}

void saveEPROM() {
  EEPROM.begin(512);
  EEPROM.put(0, globalConfig);
  EEPROM.commit();
}
