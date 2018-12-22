#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server(80);

String getJSON() {
  return "{\"temperature\":"+toString(temp_c)+",\"humidity\":"+toString(humidity)+",\"r1\":"+r1+",\"r2\":"+r2+"}";
}

void responseJSON(String json) {
  server.send(200, "application/json", json);
  delay(100);
}

void responseJSON(String json, int statusCode) {
  server.send(statusCode, "application/json", json);
}

void setupWebServer() {
  server.on("/", [](){ 
    responseJSON(getJSON()); 
  });
  
  server.on("/r1/on", HTTP_POST, [](){ toggleR1(true); server.send(204); delay(100); });
  server.on("/r1/off", HTTP_POST, [](){ toggleR1(false); server.send(204); delay(100); });

  server.on("/r2/on", HTTP_POST, [](){ toggleR2(true); server.send(204); delay(100); });
  server.on("/r2/off", HTTP_POST, [](){ toggleR2(false); server.send(204); delay(100); });

  server.on("/eeprom", HTTP_GET, [](){ 
    responseJSON(getEEPROMJSON()); 
  });
  
  server.on("/eeprom", HTTP_POST, [](){ 
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(server.arg("plain"));

    if (!root.success()) {
      responseJSON("{\"error\": \"malformed request body\"}", 400);
      return;
    }

    #ifdef DEBUG
      Serial.print("refreshRate: ");
      Serial.println(root["refreshRate"].as<int>());
    #endif

    int refreshRate = root["refreshRate"].as<int>();
    if (refreshRate < 1000) {
      responseJSON("{\"error\": \"refreshDate must be greater than 1000\"}", 400);
      return;
    }
    
    globalConfig.refreshRate = refreshRate;
    
    saveEPROM();
    
    server.send(204); 
    delay(100); 
  });

  server.begin();

  #ifdef DEBUG
    Serial.println("HTTP server started");
  #endif
}

void loopWebserver() {
  server.handleClient();
}
