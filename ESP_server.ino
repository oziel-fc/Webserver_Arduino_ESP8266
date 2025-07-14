#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "htmlLoginLib.h"
#include "htmlMainLib.h"
#include "htmlOthersLib.h"

// Wi-Fi settings
const char* ssid = "SSID";        // Wi-Fi Network name
const char* password = "password";  // Wi-Fi Network password

ESP8266WebServer server(80); // Create the server on port 80

String buttonState = "-"; // Variable to control the button state (+ or -)

// Login credentials
const String correctUsername = "admin";
const String correctPassword = "admin";

// HTML for login page
String htmlLoginPage = htmlText_LoginPage();

// HTML for main page
String htmlMainPage = htmlText_MainPage();

// HTML for redirect page
String htmlRedirectPage = htmlText_RedirectPage();

// Function to ensure access only to the login page route
void blockOtherRoutes() {
  String htmlBlockedRoutes = htmlText_BlockOthersRoutes();

  server.send(303, "text/html", htmlBlockedRoutes);
}

// Fuction to verify the login credentials
void verifyLogin() {
  String username = server.arg("username");
  String password = server.arg("password");

  if (correctUsername == username && correctPassword == password) {
    server.send(200, "text/html", htmlMainPage);
  }
  else {
    server.send(200, "text/html", htmlRedirectPage);
  }
}

// Function to toggle and send the current button value to the Serial Monitor
void toggleButtonValue() {
    // Toggles between - and + in the buttonState variable
    if (buttonState == "-") {
        buttonState = "+";
        Serial.println(buttonState);  // Sends the value + to the Serial Monitor
    } else {
        buttonState = "-";
        Serial.println(buttonState);  // Sends the value - to the Serial Monitor
    }
    server.send(200, "text/plain", "");
}

void setup() {
  // Initializes Serial communication
  Serial.begin(115200);

  // Connects to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  Serial.print("SSID: ");
  Serial.print(WiFi.SSID());
  Serial.println();
  Serial.print("Address IP: ");
  Serial.println(WiFi.localIP());

  // Configure the server routes 
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlLoginPage);
  });

  server.on("/login", HTTP_POST, verifyLogin);

  // Configure to execute the toggleButtonValue every time the button is clicked
  server.on("/toggle-button", toggleButtonValue);

  // Redirect any other route to the login page
  server.onNotFound(blockOtherRoutes);

  // Starts the server
  server.begin();
  Serial.println("Server On!");
}

void loop() {
  // Runs the server
  server.handleClient();
}

// End ;)