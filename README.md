# About the Project  
This project was developed using an Arduino and an ESP8266 Wi-Fi module to create a local web server with a basic HTML login interface.

## Features

- The ESP8266 connects to your Wi-Fi network and creates a local server.
- It provides an HTML login page and manages the necessary routes for authentication and control.
- Communication between the ESP8266 and the Arduino is done via Serial Monitor, with the Arduino responsible for receiving the values and controlling the connected devices.

## Configuration  

1. **Connect Arduino and ESP8266**:
   - See how to connect [here](https://medium.com/@abdulhamidrpn/how-to-communicate-with-arduino-to-esp8266-wifi-module-via-serial-communication-2110bc626b91).

2. **Wi-Fi Network**:  
   - In the ESP8266 code, configure the network name (SSID) and the Wi-Fi password.
      ```
      const char* ssid = "SSID";        // Wi-Fi Network name
      const char* password = "password";  // Wi-Fi Network password
      ```
      
3. **Login Credentials**:  
   - Set the username and password for the login page.
      ```
      const String correctUsername = "admin";
      const String correctPassword = "admin";
      ```
      
4. **Setup**:  
   - You need to upload the "ESP_server.ino" file to your ESP8266 device and upload the "arduino_controller.ino" file to your Arduino device.

5. **Connection and Access**:  
   - After configuring and uploading the code, the ESP8266 will try to connect to the Wi-Fi network.  
   - If everything is set up correctly, the Serial Monitor will display the IP address of the local server.  
   - Copy the IP and paste it into the browser's address bar to access the web server.

## Demonstration

- In this example code, an LED is used to demonstrate the button functionality on the web server.
- The button on the HTML page can be used to turn the LED on and off.

## Possible Applications  

- **Smart Home Use**: Lighting control, control of household devices, task automation.  
- **Agriculture Use**: Temperature control, automated irrigation, environmental monitoring.  
- **Security System Use**: Door access control, smart locks, turnstiles.

## Notes

- Make sure the [`<ESP8266WiFi.h>`](https://arduino.esp8266.com/stable/package_esp8266com_index.json) and [`<ESP8266WebServer.h>`](https://arduino.esp8266.com/stable/package_esp8266com_index.json) libraries are installed in your Arduino IDE. [See how to install](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/).
- Ensure that the SSID, Wi-Fi password, username, and login password are correct.
- The system will display messages in the Serial Monitor, such as connection status and login results.

## Credits

Developed by [oziel-fc](https://github.com/oziel-fc)

This project is part of my personal portfolio. Feel free to explore, suggest improvements, or contribute!
