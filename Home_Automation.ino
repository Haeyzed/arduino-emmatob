#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "index.h"
#include "temperature.h"
#include "led.h"
#include "error_404.h"
#include "error_405.h"
#include "socket.h"

#define LED_PIN 18  // ESP32 pin GPIO18 connected to LED
#define SOCKET_PIN 17  // ESP32 pin GPIO17 to switch Socket

const char *ssid = "ARM";     // CHANGE IT
const char *password = "arm11111";  // CHANGE IT

AsyncWebServer server(80);

int LED_state = LOW;
int SOCKET_state = LOW;

float getTemperature() {
  // YOUR SENSOR IMPLEMENTATION HERE
  // simulate the temperature value
  float temp_x100 = random(2500, 2900);  // a ramdom value from 0 to 10000
  return temp_x100 / 100;              // return the simulated temperature value from 0 to 100 in float
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SOCKET_PIN, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

  // Serve the specified HTML pages
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("Web Server: ETIA SMART Home");
    String html = HTML_CONTENT_HOME;  // Use the HTML content from the index.h file
    request->send(200, "text/html", html);
  });

  server.on("/temperature.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("Web Server: ETIA HVAC Monitoring");
    String html = HTML_CONTENT_TEMPERATURE;  // Use the HTML content from the temperature.h file
    float temperature = getTemperature();
    html.replace("%TEMPERATURE_VALUE%", String(temperature));  // update the temperature value
    request->send(200, "text/html", html);
  });


  server.on("/led.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.print("Web Server: Lighting");
    // Check for the 'state' parameter in the query string
    if (request->hasArg("state")) {
      String state = request->arg("state");
      if (state == "on") {
        LED_state = HIGH;
      } else if (state == "off") {
        LED_state = LOW;
      }

      // control LED here
      digitalWrite(LED_PIN, LED_state);
      Serial.print(" => turning LED to ");
      Serial.print(state);
    }
    Serial.println();

    String html = HTML_CONTENT_LED;                         // Use the HTML content from the led.h file
    html.replace("%LED_STATE%", LED_state ? "ON" : "OFF");  // update the LED state
    request->send(200, "text/html", html);
  });



server.on("/socket.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.print("Web Server: Socket");
    // Check for the 'state' parameter in the query string
    if (request->hasArg("state")) {
      String state = request->arg("state");
      if (state == "on") {
        SOCKET_state = HIGH;
      } else if (state == "off") {
        SOCKET_state = LOW;
      }

      // control SOCKET here
      digitalWrite(SOCKET_PIN, SOCKET_state);
      Serial.print(" => turning SOCKET to ");
      Serial.print(state);
    }
    Serial.println();

    String html = HTML_CONTENT_SOCKET;                         // Use the HTML content from the Socket.h file
    html.replace("%SOCKET_STATE%", SOCKET_state ? "ON" : "OFF");  // update the SOCKET state
    request->send(200, "text/html", html);
  });


  // 404 and 405 error handler
  server.onNotFound([](AsyncWebServerRequest *request) {
    if (request->method() == HTTP_GET) {
      // Handle 404 Not Found error
      Serial.println("Web Server: Not Found");
      String html = HTML_CONTENT_404;  // Use the HTML content from the error_404.h file
      request->send(404, "text/html", html);
    } else {
      // Handle 405 Method Not Allowed error
      Serial.println("Web Server: Method Not Allowed");
      String html = HTML_CONTENT_405;  // Use the HTML content from the error_405.h file
      request->send(405, "text/html", html);
    }
  });

  server.begin();
  Serial.println("ESP32 Web server started");
}

void loop() {
  // Your code can go here or be empty; the server is handled asynchronously
}
