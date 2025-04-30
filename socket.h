const char *HTML_CONTENT_SOCKET = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="icon" href="data:,">
    <title>Socket</title>
</head>
<body>
    <h1>Socket</h1>
    <p>SOCKET State: <span style="color: red;">%SOCKET_STATE%</span></p>
    <a href='/socket.html?state=on'>Turn ON</a>
    <br><br>
    <a href='/socket.html?state=off'>Turn OFF</a>
</body>
</html>
)=====";
