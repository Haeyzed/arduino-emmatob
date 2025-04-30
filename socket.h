const char *HTML_CONTENT_SOCKET = R"=====(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <link rel="icon" href="data:,">
      <title>Socket Control - Emmatob International Academy</title>
      <style>
          :root {
              --primary: #3a5a97;
              --secondary: #f8b400;
              --accent: #e63946;
              --light: #f1faee;
              --dark: #1d3557;
              --success: #2a9d8f;
              --danger: #e63946;
          }
          
          * {
              margin: 0;
              padding: 0;
              box-sizing: border-box;
              font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
          }
          
          body {
              background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
              min-height: 100vh;
              display: flex;
              flex-direction: column;
              color: var(--dark);
          }
          
          .container {
              width: 100%;
              max-width: 1200px;
              margin: 0 auto;
              padding: 20px;
          }
          
          header {
              background-color: var(--primary);
              color: white;
              padding: 1rem 0;
              box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
          }
          
          .header-content {
              display: flex;
              align-items: center;
              justify-content: space-between;
          }
          
          .logo-container {
              display: flex;
              align-items: center;
              gap: 1rem;
          }
          
          .logo {
              width: 60px;
              height: 60px;
              background-color: white;
              border-radius: 50%;
              display: flex;
              align-items: center;
              justify-content: center;
              font-weight: bold;
              font-size: 1.5rem;
              color: var(--primary);
          }
          
          h1 {
              font-size: 1.8rem;
              margin: 0;
          }
          
          .back-link {
              color: white;
              text-decoration: none;
              display: flex;
              align-items: center;
              gap: 0.5rem;
          }
          
          main {
              flex: 1;
              padding: 2rem 0;
          }
          
          .socket-card {
              background-color: white;
              border-radius: 10px;
              padding: 2rem;
              margin-bottom: 2rem;
              box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
              text-align: center;
              max-width: 600px;
              margin-left: auto;
              margin-right: auto;
          }
          
          .socket-card h2 {
              color: var(--primary);
              margin-bottom: 1.5rem;
          }
          
          .socket-status {
              font-size: 1.2rem;
              margin-bottom: 2rem;
              padding: 1rem;
              border-radius: 8px;
              background-color: #f8f9fa;
              display: flex;
              align-items: center;
              justify-content: center;
              gap: 0.5rem;
          }
          
          .status-indicator {
              width: 20px;
              height: 20px;
              border-radius: 50%;
              display: inline-block;
          }
          
          .status-on {
              background-color: var(--success);
              box-shadow: 0 0 10px var(--success);
          }
          
          .status-off {
              background-color: var(--danger);
          }
          
          .socket-buttons {
              display: flex;
              gap: 1.5rem;
              justify-content: center;
              margin-bottom: 2rem;
          }
          
          .socket-btn {
              padding: 1rem 2rem;
              border: none;
              border-radius: 50px;
              font-size: 1.1rem;
              font-weight: bold;
              cursor: pointer;
              transition: all 0.3s ease;
              display: flex;
              align-items: center;
              gap: 0.5rem;
              min-width: 160px;
              justify-content: center;
          }
          
          .btn-on {
              background-color: var(--success);
              color: white;
          }
          
          .btn-on:hover {
              background-color: #218778;
              box-shadow: 0 4px 8px rgba(42, 157, 143, 0.3);
              transform: translateY(-2px);
          }
          
          .btn-off {
              background-color: var(--danger);
              color: white;
          }
          
          .btn-off:hover {
              background-color: #d62b39;
              box-shadow: 0 4px 8px rgba(230, 57, 70, 0.3);
              transform: translateY(-2px);
          }
          
          .socket-info {
              background-color: #f8f9fa;
              padding: 1rem;
              border-radius: 8px;
              font-size: 0.9rem;
              color: #666;
          }
          
          footer {
              background-color: var(--primary);
              color: white;
              padding: 1rem 0;
              text-align: center;
              margin-top: auto;
          }
          
          @media (max-width: 768px) {
              .header-content {
                  flex-direction: column;
                  text-align: center;
                  gap: 1rem;
              }
              
              .logo-container {
                  justify-content: center;
              }
              
              h1 {
                  font-size: 1.5rem;
              }
              
              .socket-buttons {
                  flex-direction: column;
                  gap: 1rem;
              }
              
              .socket-btn {
                  width: 100%;
              }
          }
          
          /* Icon for socket buttons */
          .icon-socket-on {
              display: inline-block;
              width: 24px;
              height: 24px;
              background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M6.09 19.44A9 9 0 0 1 2 12c0-5 4-9 9-9s9 4 9 9a9 9 0 0 1-3.18 6.88'%3E%3C/path%3E%3Cline x1='12' y1='12' x2='12' y2='20'%3E%3C/line%3E%3Cline x1='8' y1='12' x2='16' y2='12'%3E%3C/line%3E%3C/svg%3E");
              background-size: contain;
              background-repeat: no-repeat;
              background-position: center;
          }
          
          .icon-socket-off {
              display: inline-block;
              width: 24px;
              height: 24px;
              background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M6.09 19.44A9 9 0 0 1 2 12c0-5 4-9 9-9s9 4 9 9a9 9 0 0 1-3.18 6.88'%3E%3C/path%3E%3Cline x1='12' y1='12' x2='12' y2='20'%3E%3C/line%3E%3Cline x1='8' y1='12' x2='16' y2='12'%3E%3C/line%3E%3C/svg%3E");
              background-size: contain;
              background-repeat: no-repeat;
              background-position: center;
          }
          
          .icon-back {
              display: inline-block;
              width: 20px;
              height: 20px;
              background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cline x1='19' y1='12' x2='5' y2='12'%3E%3C/line%3E%3Cpolyline points='12 19 5 12 12 5'%3E%3C/polyline%3E%3C/svg%3E");
              background-size: contain;
              background-repeat: no-repeat;
              background-position: center;
          }
      </style>
  </head>
  <body>
      <header>
          <div class="container header-content">
              <div class="logo-container">
                  <div class="logo">EIA</div>
                  <h1>Emmatob International Academy</h1>
              </div>
              <a href="/" class="back-link">
                  <span class="icon-back"></span>
                  Back to Home
              </a>
          </div>
      </header>
      
      <main>
          <div class="container">
              <div class="socket-card">
                  <h2>Socket Control System</h2>
                  
                  <div class="socket-status">
                      <span class="status-indicator %SOCKET_STATE_CLASS%"></span>
                      Socket is currently <strong>%SOCKET_STATE%</strong>
                  </div>
                  
                  <div class="socket-buttons">
                      <a href='/socket.html?state=on'>
                          <button class="socket-btn btn-on">
                              <span class="icon-socket-on"></span>
                              Turn ON
                          </button>
                      </a>
                      
                      <a href='/socket.html?state=off'>
                          <button class="socket-btn btn-off">
                              <span class="icon-socket-off"></span>
                              Turn OFF
                          </button>
                      </a>
                  </div>
                  
                  <div class="socket-info">
                      <p>This control manages the power outlets throughout the campus buildings.</p>
                  </div>
              </div>
          </div>
      </main>
      
      <footer>
          <div class="container">
              <p>&copy; 2023 Emmatob International Academy. All rights reserved.</p>
          </div>
      </footer>
  </body>
  </html>
  )=====";
  