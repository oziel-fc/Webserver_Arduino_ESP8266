String LED_State = ""; // String to store the message received through serial port 3.

void setup() {
  // Set the LED_BUILTIN pin (10) as output.
  pinMode(10, OUTPUT);
  // Set the serial port for USB communication.
  Serial.begin(115200);
  // Set the serial port for communication with ESP8266.
  Serial3.begin(115200);
}

void loop() {
  // Wait for data from the ESP8266.
  if (Serial3.available()) {
    // Read a byte.
    char data = Serial3.read();
    // Print the same data through the USB port.
    Serial.print(data);
    
    LED_State += data;
    if (LED_State == "+") {
      digitalWrite(10, HIGH);
      Serial.print(" LED On");
    }
    else if (LED_State == "-") {
      digitalWrite(10, LOW);
      Serial.print(" LED Off");
    }
    LED_State = "";
  }
}
