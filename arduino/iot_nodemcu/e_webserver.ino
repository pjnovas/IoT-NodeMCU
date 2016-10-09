#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String getJSON() {
  return "{\"temperature\":"+toString(temp_c)+",\"humidity\":"+toString(humidity)+",\"r1\":"+r1+",\"r2\":"+r2+"}";
}

void handle_root() {
  server.send(200, "application/json", getJSON());
  delay(100);
}

void setupWebServer() {
  server.on("/", handle_root);

  server.on("/r1/on", HTTP_POST, [](){ toggleR1(true); server.send(204); delay(100); });
  server.on("/r1/off", HTTP_POST, [](){ toggleR1(false); server.send(204); delay(100); });

  server.on("/r2/on", HTTP_POST, [](){ toggleR2(true); server.send(204); delay(100); });
  server.on("/r2/off", HTTP_POST, [](){ toggleR2(false); server.send(204); delay(100); });

  server.begin();

  #ifdef DEBUG
    Serial.println("HTTP server started");
  #endif
}

void loopWebserver() {
  server.handleClient();
}
