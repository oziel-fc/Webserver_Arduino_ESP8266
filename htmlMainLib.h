#ifndef HTMLMAINPAGE_H
#define HTMLMAINPAGE_H
#include <Arduino.h>


String htmlText_MainPage() {
    return R"rawliteral(
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
}

#endif
