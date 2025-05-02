const char *HTML_CONTENT_LED = R"=====(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <link rel="icon" href="data:,">
      <title>Lighting Control - Emmatob International Academy</title>
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
          
          .lighting-card {
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
          
          .lighting-card h2 {
              color: var(--primary);
              margin-bottom: 1.5rem;
          }
          
          .light-status {
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
              background-color: var(--secondary);
              box-shadow: 0 0 10px var(--secondary);
          }
          
          .status-off {
              background-color: #adb5bd;
          }
          
          .light-buttons {
              display: flex;
              gap: 1.5rem;
              justify-content: center;
              margin-bottom: 2rem;
          }
          
          .light-btn {
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
              background-color: var(--secondary);
              color: var(--dark);
          }
          
          .btn-on:hover {
              background-color: #e0a800;
              box-shadow: 0 4px 8px rgba(248, 180, 0, 0.3);
              transform: translateY(-2px);
          }
          
          .btn-off {
              background-color: #adb5bd;
              color: white;
          }
          
          .btn-off:hover {
              background-color: #6c757d;
              box-shadow: 0 4px 8px rgba(108, 117, 125, 0.3);
              transform: translateY(-2px);
          }
          
          .light-info {
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
              
              .light-buttons {
                  flex-direction: column;
                  gap: 1rem;
              }
              
              .light-btn {
                  width: 100%;
              }
          }
          
          /* Icon for light buttons */
          .icon-light-on {
              display: inline-block;
              width: 24px;
              height: 24px;
              background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='%231d3557' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3C  stroke='%231d3557' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M15 14c.2-1 .7-1.7 1.5-2.5 1-.9 1.5-2.2 1.5-3.5A6 6 0 0 0 6 8c0 1 .2 2.2 1.5 3.5.7.7 1.3 1.5 1.5 2.5'%3E%3C/path%3E%3Cpath d='M9 18h6'%3E%3C/path%3E%3Cpath d='M10 22h4'%3E%3C/path%3E%3C/svg%3E");
              background-size: contain;
              background-repeat: no-repeat;
              background-position: center;
          }
          
          .icon-light-off {
              display: inline-block;
              width: 24px;
              height: 24px;
              background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M15 14c.2-1 .7-1.7 1.5-2.5 1-.9 1.5-2.2 1.5-3.5A6 6 0 0 0 6 8c0 1 .2 2.2 1.5 3.5.7.7 1.3 1.5 1.5 2.5'%3E%3C/path%3E%3Cpath d='M9 18h6'%3E%3C/path%3E%3Cpath d='M10 22h4'%3E%3C/path%3E%3C/svg%3E");
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
              <div class="lighting-card">
                  <h2>Lighting Control System</h2>
                  
                  <div class="light-status">
                      <span class="status-indicator %LED_STATE_CLASS%"></span>
                      Lighting is currently <strong>%LED_STATE%</strong>
                  </div>
                  
                  <div class="light-buttons">
                      <a href="/led.html?state=on">
                          <button class="light-btn btn-on">
                              <span class="icon-light-on"></span>
                              Turn ON
                          </button>
                      </a>
                      
                      <a href="/led.html?state=off">
                          <button class="light-btn btn-off">
                              <span class="icon-light-off"></span>
                              Turn OFF
                          </button>
                      </a>
                  </div>
                  
                  <div class="light-info">
                      <p>This control manages the lighting systems throughout the campus buildings.</p>
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
  