# Local Web Server Project with ESP8266 and Arduino

This project was developed using an Arduino and an ESP8266 WiFi module to create a local web server with a basic HTML login interface.

## Features

- The ESP8266 connects to your WiFi network and creates a local server.
- It provides an HTML login page and manages the necessary routes for authentication and control.
- Communication between the ESP8266 and Arduino is done via the Serial Monitor, with the Arduino being responsible for receiving values and controlling the connected devices.

## Setup

### 1. WiFi Network
In the ESP8266 code, configure the name of the network (SSID) and the password of your WiFi.

### 2. Login Credentials
Set the username and password for the login page.

### 3. Upload the Files
Upload the `ESP_server.ino` file to your ESP8266 device and the `arduino_controller.ino` file to your Arduino device.

### 4. Connection and Access
- After configuring and uploading the code, the ESP8266 will attempt to connect to the WiFi network.
- If everything is configured correctly, the Serial Monitor will display the local server's IP address.
- Copy the IP address and paste it into the browser's address bar to access the web server.

## Demonstration

In this example, an LED is used to demonstrate the functionality of the button on the web server.

- The button on the HTML page can be used to turn the LED on and off.
- **Possible applications**: Control of relays, motors, sensors, and other devices.

## Notes

- Make sure the `<ESP8266WiFi.h>` and `<ESP8266WebServer.h>` libraries are installed in your Arduino IDE.
- Ensure that the SSID, WiFi password, username, and login password are correct.
- The system will display messages in the Serial Monitor, such as the connection status and the login result.

## License

Distributed under the MIT License. See `LICENSE` for more information.
