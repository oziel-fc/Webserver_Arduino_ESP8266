#ifndef HTMLOTHERSPAGE_H
#define HTMLOTHERSPAGE_H
#include <Arduino.h>


String htmlText_RedirectPage() {
    return R"rawliteral(
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
}

String htmlText_BlockOthersRoutes () {
    return R"rawliteral(
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
}

#endif
