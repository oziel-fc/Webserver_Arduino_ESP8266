#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi settings
const char* ssid = "SSID";        // Wi-Fi Network name
const char* password = "password";  // Wi-Fi Network password

ESP8266WebServer server(80); // Create the server on port 80

String buttonState = "-"; // Variable to control the button state (+ or -)

// Login credentials
const String correctUsername = "admin";
const String correctPassword = "admin";

// HTML for login page
String htmlLoginPage = R"rawliteral(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Login Page</title>
  </head>
  <style>
      *,
  ::after,
  ::before {
    box-sizing: border-box;
  }

  body {
      height: 100vh;
      background-color: #212121;
      color: black;
      font-family: monospace, serif;
      letter-spacing: 0.05em;
      display: flex;
      justify-content: center;
      align-items: center;
  }
  #bgForm {
      background-color: white;
      height: 50vh;
      width: 25vw;
      border-radius: 3%;
  }

  h1 {
      font-size: 23px;
  }

  .form {
      width: 300px;
      padding: 64px 15px 24px;
      margin: 0 auto;
  }
  .form .control {
      margin: 0 0 24px;
  }
  .form .control input {
      width: 100%;
      padding: 14px 16px;
      border: 0;
      background: transparent;
      color: #fff;
      font-family: monospace, serif;
      letter-spacing: 0.05em;
      font-size: 16px;
  }
  .form .control input:hover, .form .control input:focus {
      outline: none;
      border: 0;
  }
  .form .btn {
      width: 100%;
      display: block;
      padding: 14px 16px;
      background: transparent;
      outline: none;
      border: 0;
      color: #fff;
      letter-spacing: 0.1em;
      font-weight: bold;
      font-family: monospace;
      font-size: 16px;
  }

  .block-cube {
      position: relative;
  }
  .block-cube .bg-top {
      position: absolute;
      height: 10px;
      background: #020024;
      background: linear-gradient(90deg, #020024 0%, #340979 37%, #00d4ff 94%);
      bottom: 100%;
      left: 5px;
      right: -5px;
      transform: skew(-45deg, 0);
      margin: 0;
  }
  .block-cube .bg-top .bg-inner {
      bottom: 0;
  }
  .block-cube .bg {
      position: absolute;
      left: 0;
      top: 0;
      right: 0;
      bottom: 0;
      background: #020024;
      background: linear-gradient(90deg, #020024 0%, #340979 37%, #00d4ff 94%);
  }
  .block-cube .bg-right {
      position: absolute;
      background: #020024;
      background: #00d4ff;
      top: -5px;
      z-index: 0;
      bottom: 5px;
      width: 10px;
      left: 100%;
      transform: skew(0, -45deg);
  }
  .block-cube .bg-right .bg-inner {
      left: 0;
  }
  .block-cube .bg .bg-inner {
      transition: all 0.2s ease-in-out;
  }
  .block-cube .bg-inner {
      background: #212121;
      position: absolute;
      left: 2px;
      top: 2px;
      right: 2px;
      bottom: 2px;
  }
  .block-cube .text {
      position: relative;
      z-index: 2;
  }
  .block-cube.block-input input {
      position: relative;
      z-index: 2;
  }
  .block-cube.block-input input:focus ~ .bg-right .bg-inner, .block-cube.block-input input:focus ~ .bg-top .bg-inner, .block-cube.block-input input:focus ~ .bg-inner .bg-inner {
      top: 100%;
      background: rgba(255, 255, 255, 0.5);
  }
  .block-cube.block-input .bg-top,
  .block-cube.block-input .bg-right,
  .block-cube.block-input .bg {
      background: rgb(0, 0, 53);
      transition: background 0.2s ease-in-out;
  }
  .block-cube.block-input .bg-right .bg-inner,
  .block-cube.block-input .bg-top .bg-inner {
      transition: all 0.2s ease-in-out;
  }
  .block-cube.block-input:focus .bg-top,
  .block-cube.block-input:focus .bg-right,
  .block-cube.block-input:focus .bg, .block-cube.block-input:hover .bg-top,
  .block-cube.block-input:hover .bg-right,
  .block-cube.block-input:hover .bg {
      background: rgb(0, 0, 53);
  }
  .block-cube.block-cube-hover:focus .bg .bg-inner, .block-cube.block-cube-hover:hover .bg .bg-inner {
      top: 100%;
  }

  /*Mobile styling*/
  @media (max-width: 768px) {
      body {
          height: 80vh;
          width: 100vw;
      }
      #bgForm {
          width: 100vw;
      }
  }

  </style>
  <body>
      <div id="bgForm">
          <form autocomplete='off' class='form' action='login' method='post'>
              <div class='control'>
                  <h1>
                      Login
                  </h1>
              </div>
              <div class='control block-cube block-input'>
                  <input name='username' placeholder='Username' type='text'>
                  <div class='bg-top'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg-right'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg'>
                      <div class='bg-inner'></div>
                  </div>
              </div>
              <div class='control block-cube block-input'>
                  <input name='password' placeholder='Password' type='password'>
                  <div class='bg-top'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg-right'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg'>
                      <div class='bg-inner'></div>
                  </div>
              </div>
              <button class='btn block-cube block-cube-hover' type='submit'>
                  <div class='bg-top'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg-right'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='bg'>
                      <div class='bg-inner'></div>
                  </div>
                  <div class='text'>
                      Log In
                  </div>
              </button>
          </form>
      </div>
  </body>
  </html>
  )rawliteral";

// HTML for main page
String htmlMainPage =  R"rawliteral(
  "<!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Main Page</title>
  </head>
  <style>
      body {
          height: 100vh;
          font-family: monospace, serif;
          text-align: center;
          background-color: #212121;
      }
      #div_title {
          background-color: #0D0D0C;
          height: 8vh;
          display: flex;
          justify-content: center;
          align-items: center;
          border-bottom: 0.1vh solid #ababab;
      }
      h1 {
          color: white;
          font-size: 4vh;
          margin: auto;
      }
      button {
          font-family: monospace, serif;
          color: white;
          background-color: #0D0D0C;
          font-size: 5vh;
          margin-top: 15vh;
          height: 9vh;
          width: 10vw;
          cursor: pointer;
          border: 0;
          border-radius: 1vh;
      }
      button:hover {
          color: #ddd;
          transform: scale(1.1);
          transition: 0.2s ease-in-out;
      }
      /*Estilização para dispositivos móveis*/
      @media (max-width: 768px) {
          body {
              height: 80vh;
          }
          button {
              font-size: 5vw;
              margin-top: 20vh;
              width: 30vw;
          }
      }
  </style>
  <body>
      <div id="div_title">
          <h1>Arduino Webserver</h1>
      </div>
      <button id="BasicButton">Off</button>
      
      <script>
          let btn = document.getElementById("BasicButton")

          function toggleButton() {
              if (btn.textContent === "Off") {
                  btn.textContent = "On"
              }
              else {
                  btn.textContent = "Off"
              }

              // Make a GET request to the ESP8266
              fetch('/toggle-button')
                  .then(response => response.text())
          }
          btn.addEventListener('click', toggleButton)
      </script>
  </body>
  </html>
  )rawliteral";

// HTML for redirect page
String htmlRedirectPage = R"rawliteral(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Redirect</title>
        <style>
            body {
                font-family: monospace, serif;
                text-align: center;
                background-color: #212121;
                color: black;
            }
        </style>
        <script>
            // Function that displays an alert when the page loads
            function showAlert() {
                alert('Incorrect password!\nYou will be redirected to try again!');
            }
        </script>
    </head>
    <body onload="showAlert()">
    <h1>Redirect Page</h1>

    <script type="text/javascript">
        setTimeout(function() {
        window.location.href = '/'; // Redirects to the login page
        }, 5000); // Waits 5 seconds before redirecting
    </script>
    </body>
    </html>

  )rawliteral";

// Function to ensure access only to the login page route
void blockOtherRoutes() {
  String htmlBlockedRoutes = R"rawliteral(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Blocked Route</title>
      <style>
          body {
              font-family: monospace, serif;
              text-align: center;
              background-color: #212121;
          }
      </style>
  </head>
  <body>
      <script>
          // Function that displays an alert when the page loads
          function showAlert() {
              alert('Incorrect route!\nYou are trying to access a route that does not exist!');
              window.location.href = '/'
          }
          showAlert()
      </script>
  </body>
  </html>
    )rawliteral";
  
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