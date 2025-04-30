const char *HTML_CONTENT_POWER = R"=====(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="icon" href="data:,">
        <title>Power Control - Emmatob International Academy</title>
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
            
            .power-card {
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
            
            .power-card h2 {
                color: var(--primary);
                margin-bottom: 1.5rem;
            }
            
            .power-status {
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
            
            .power-buttons {
                display: flex;
                gap: 1.5rem;
                justify-content: center;
                margin-bottom: 2rem;
            }
            
            .power-btn {
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
            
            .power-info {
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
                
                .power-buttons {
                    flex-direction: column;
                    gap: 1rem;
                }
                
                .power-btn {
                    width: 100%;
                }
            }
            
            /* Icon for power buttons */
            .icon-power-on {
                display: inline-block;
                width: 24px;
                height: 24px;
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M18.36 6.64a9 9 0 1 1-12.73 0'%3E%3C/path%3E%3Cline x1='12' y1='2' x2='12' y2='12'%3E%3C/line%3E%3C/svg%3E");
                background-size: contain;
                background-repeat: no-repeat;
                background-position: center;
            }
            
            .icon-power-off {
                display: inline-block;
                width: 24px;
                height: 24px;
                background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='white' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M18.36 6.64a9 9 0 1 1-12.73 0'%3E%3C/path%3E%3Cline x1='12' y1='2' x2='12' y2='12'%3E%3C/line%3E%3C/svg%3E");
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
                <div class="power-card">
                    <h2>Power Control System</h2>
                    
                    <div class="power-status">
                        <span class="status-indicator %STATUS_CLASS%"></span>
                        Power is currently <strong>%POWER_STATE%</strong>
                    </div>
                    
                    <div class="power-buttons">
                        <a href="/power.html?state=on" onclick="speakPowerOn()">
                            <button class="power-btn btn-on">
                                <span class="icon-power-on"></span>
                                Power ON
                            </button>
                        </a>
                        
                        <a href="/power.html?state=off" onclick="speakPowerOff()">
                            <button class="power-btn btn-off">
                                <span class="icon-power-off"></span>
                                Power OFF
                            </button>
                        </a>
                    </div>
                    
                    <div class="power-info">
                        <p>This control manages the main power systems for the campus. Please use responsibly.</p>
                    </div>
                </div>
            </div>
        </main>
        
        <footer>
            <div class="container">
                <p>&copy; 2023 Emmatob International Academy. All rights reserved.</p>
            </div>
        </footer>
        
        <script>
            function speakPowerOn() {
                if ('speechSynthesis' in window) {
                    const msg = new SpeechSynthesisUtterance("Power is ON");
                    window.speechSynthesis.speak(msg);
                }
            }
            
            function speakPowerOff() {
                if ('speechSynthesis' in window) {
                    const msg = new SpeechSynthesisUtterance("Power is OFF");
                    window.speechSynthesis.speak(msg);
                }
            }
            
            // Auto-speak current state when page loads
            window.onload = function() {
                const currentState = "%POWER_STATE%";
                if ('speechSynthesis' in window) {
                    const msg = new SpeechSynthesisUtterance("Power is " + currentState);
                    window.speechSynthesis.speak(msg);
                }
            };
        </script>
    </body>
    </html>
    )=====";
    