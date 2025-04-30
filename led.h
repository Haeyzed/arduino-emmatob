const char *HTML_CONTENT_LED = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="icon" href="data:,">
    <title>Lighting</title>
</head>
<body>
    <h1>Lighting</h1>
    <p>LED State: <span style="color: red;">%LED_STATE%</span></p>
    <a href='/led.html?state=on'>Turn ON</a>
    <br><br>
    <a href='/led.html?state=off'>Turn OFF</a>
</body>
</html>
)=====";
