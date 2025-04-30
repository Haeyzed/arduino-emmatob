const char *HTML_CONTENT_HOME = R"=====(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="icon" href="data:,">
        <title>Emmatob International Academy</title>
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
            
            main {
                flex: 1;
                padding: 2rem 0;
            }
            
            .welcome-card {
                background-color: white;
                border-radius: 10px;
                padding: 2rem;
                margin-bottom: 2rem;
                box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
                text-align: center;
            }
            
            .welcome-card h2 {
                color: var(--primary);
                margin-bottom: 1rem;
            }
            
            .welcome-card p {
                color: var(--dark);
                line-height: 1.6;
                margin-bottom: 1.5rem;
            }
            
            .menu-grid {
                display: grid;
                grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
                gap: 1.5rem;
            }
            
            .menu-item {
                background-color: white;
                border-radius: 10px;
                padding: 1.5rem;
                box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
                transition: transform 0.3s ease, box-shadow 0.3s ease;
                text-align: center;
                display: flex;
                flex-direction: column;
                align-items: center;
                justify-content: center;
                text-decoration: none;
                color: var(--dark);
                min-height: 200px;
            }
            
            .menu-item:hover {
                transform: translateY(-5px);
                box-shadow: 0 10px 15px rgba(0, 0, 0, 0.1);
            }
            
            .menu-item i {
                font-size: 3rem;
                margin-bottom: 1rem;
                color: var(--primary);
            }
            
            .menu-item h3 {
                margin-bottom: 0.5rem;
                color: var(--primary);
            }
            
            .menu-item p {
                color: #666;
                font-size: 0.9rem;
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
            }
            
            /* Icons using CSS */
            .icon {
                display: inline-block;
                width: 60px;
                height: 60px;
                margin-bottom: 1rem;
                background-size: contain;
                background-repeat: no-repeat;
                background-position: center;
            }
            
            .icon-power {
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='%233a5a97' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M18.36 6.64a9 9 0 1 1-12.73 0'%3E%3C/path%3E%3Cline x1='12' y1='2' x2='12' y2='12'%3E%3C/line%3E%3C/svg%3E");
            }
            
            .icon-light {
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='%233a5a97' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M15 14c.2-1 .7-1.7 1.5-2.5 1-.9 1.5-2.2 1.5-3.5A6 6 0 0 0 6 8c0 1 .2 2.2 1.5 3.5.7.7 1.3 1.5 1.5 2.5'%3E%3C/path%3E%3Cpath d='M9 18h6'%3E%3C/path%3E%3Cpath d='M10 22h4'%3E%3C/path%3E%3C/svg%3E");
            }
            
            .icon-temp {
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='%233a5a97' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M14 14.76V3.5a2.5 2.5 0 0 0-5 0v11.26a4.5 4.5 0 1 0 5 0z'%3E%3C/path%3E%3C/svg%3E");
            }
            
            .icon-socket {
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='%233a5a97' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M6.09 19.44A9 9 0 0 1 2 12c0-5 4-9 9-9s9 4 9 9a9 9 0 0 1-3.18 6.88'%3E%3C/path%3E%3Cline x1='12' y1='12' x2='12' y2='20'%3E%3C/line%3E%3Cline x1='8' y1='12' x2='16' y2='12'%3E%3C/line%3E%3C/svg%3E");
            }
        </style>
    </head>
    <body onload="speakWelcome()">
        <header>
            <div class="container header-content">
                <div class="logo-container">
                    <div class="logo">EIA</div>
                    <h1>Emmatob International Academy</h1>
                </div>
            </div>
        </header>
        
        <main>
            <div class="container">
                <div class="welcome-card">
                    <h2>Welcome to Our Smart Campus</h2>
                    <p>Control and monitor our campus systems through this intuitive interface. Select one of the options below to get started.</p>
                </div>
                
                <div class="menu-grid">
                    <a href="/power.html" class="menu-item">
                        <div class="icon icon-power"></div>
                        <h3>Power Control</h3>
                        <p>Turn campus power systems on or off</p>
                    </a>
                    
                    <a href="/led.html" class="menu-item">
                        <div class="icon icon-light"></div>
                        <h3>Lighting Control</h3>
                        <p>Manage campus lighting systems</p>
                    </a>
                    
                    <a href="/temperature.html" class="menu-item">
                        <div class="icon icon-temp"></div>
                        <h3>HVAC Monitoring</h3>
                        <p>Monitor temperature and climate control</p>
                    </a>
                    
                    <a href="/socket.html" class="menu-item">
                        <div class="icon icon-socket"></div>
                        <h3>Socket Control</h3>
                        <p>Control power outlets around campus</p>
                    </a>
                </div>
            </div>
        </main>
        
        <footer>
            <div class="container">
                <p>&copy; 2023 Emmatob International Academy. All rights reserved.</p>
            </div>
        </footer>
        
        <script>
            function speakWelcome() {
                // Check if browser supports speech synthesis
                if ('speechSynthesis' in window) {
                    const msg = new SpeechSynthesisUtterance("Welcome to Emmatob International Academy");
                    msg.rate = 0.9;  // Slightly slower rate for clarity
                    msg.pitch = 1;   // Normal pitch
                    window.speechSynthesis.speak(msg);
                }
            }
        </script>
    </body>
    </html>
    )=====";
    