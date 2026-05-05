<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Solar System Adventure for Kids</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Comic+Neue:wght@400;700&display=swap');
        body {
            font-family: 'Comic Neue', cursive;
            background: linear-gradient(135deg, #1a2a6c, #b21f1f, #1a2a6c);
            overflow-x: hidden;
        }
        .planet {
            position: absolute;
            border-radius: 50%;
            box-shadow: 0 0 15px rgba(255, 255, 255, 0.5);
            transition: transform 0.5s ease;
        }
        .planet:hover {
            transform: scale(1.1);
        }
        .orbit {
            position: absolute;
            border: 1px solid rgba(255, 255, 255, 0.2);
            border-radius: 50%;
            transform: translate(-50%, -50%);
        }
        .info-panel {
            background: rgba(255, 255, 255, 0.9);
            border-radius: 20px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
            transition: all 0.3s ease;
        }
        .star {
            position: absolute;
            background-color: white;
            border-radius: 50%;
            animation: twinkle var(--duration, 3s) infinite ease-in-out;
        }
        @keyframes twinkle {
            0%, 100% { opacity: 0.2; }
            50% { opacity: 1; }
        }
        .floating {
            animation: floating 3s ease-in-out infinite;
        }
        @keyframes floating {
            0%, 100% { transform: translateY(0); }
            50% { transform: translateY(-20px); }
        }
    </style>
</head>
<body class="min-h-screen relative">
    <!-- Background Stars -->
    <div id="stars-container"></div>
    
    <!-- Header -->
    <header class="relative z-10 bg-gradient-to-r from-blue-500 to-purple-600 text-white p-4 shadow-lg">
        <div class="container mx-auto flex justify-between items-center">
            <h1 class="text-3xl md:text-4xl font-bold flex items-center">
                <i class="fas fa-sun mr-3"></i> Solar System Adventure
            </h1>
            <div class="hidden md:flex space-x-4">
                <button onclick="showPlanet('sun')" class="bg-yellow-400 hover:bg-yellow-500 text-gray-800 font-bold py-2 px-4 rounded-full transition transform hover:scale-105">
                    Sun
                </button>
                <button onclick="showPlanet('earth')" class="bg-blue-400 hover:bg-blue-500 text-white font-bold py-2 px-4 rounded-full transition transform hover:scale-105">
                    Earth
                </button>
                <button onclick="showPlanet('moon')" class="bg-gray-300 hover:bg-gray-400 text-gray-800 font-bold py-2 px-4 rounded-full transition transform hover:scale-105">
                    Moon
                </button>
            </div>
        </div>
    </header>

    <!-- Main Content -->
    <main class="relative z-10 container mx-auto px-4 py-8">
        <div class="flex flex-col lg:flex-row gap-8 items-center">
            <!-- Solar System Visualization -->
            <div class="w-full lg:w-2/3">
                <div id="solar-system" class="relative w-full h-[500px] bg-black rounded-xl overflow-hidden shadow-2xl">
                    <!-- Orbits will be generated here -->
                    <div class="absolute top-1/2 left-1/2 transform -translate-x-1/2 -translate-y-1/2">
                        <!-- Sun -->
                        <div id="sun" class="planet w-24 h-24 bg-gradient-to-br from-yellow-300 to-orange-500 rounded-full shadow-lg floating" style="top: 50%; left: 50%;">
                            <div class="absolute inset-0 rounded-full bg-yellow-200 animate-pulse"></div>
                        </div>
                    </div>
                </div>
                
                <!-- Controls -->
                <div class="mt-6 flex justify-center space-x-4">
                    <button id="play-btn" onclick="toggleAnimation()" class="bg-green-500 hover:bg-green-600 text-white font-bold py-3 px-6 rounded-full shadow-lg transition transform hover:scale-105">
                        <i class="fas fa-play mr-2"></i>Play
                    </button>
                    <button onclick="resetSystem()" class="bg-red-500 hover:bg-red-600 text-white font-bold py-3 px-6 rounded-full shadow-lg transition transform hover:scale-105">
                        <i class="fas fa-redo mr-2"></i>Reset
                    </button>
                </div>
            </div>

            <!-- Info Panel -->
            <div class="w-full lg:w-1/3">
                <div class="info-panel p-6 h-full">
                    <h2 class="text-2xl font-bold text-blue-600 mb-4 flex items-center">
                        <i class="fas fa-info-circle mr-2"></i> Planet Facts
                    </h2>
                    <div id="planet-info" class="space-y-4">
                        <p class="text-lg">Welcome to our Solar System Adventure!</p>
                        <p><strong>Tip:</strong> Click on planets to learn more about them.</p>
                        <div class="bg-blue-100 p-4 rounded-lg mt-4">
                            <h3 class="font-bold text-blue-700">Did You Know?</h3>
                            <p>The Sun is actually a star and it's at the center of our solar system!</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <!-- Planet Cards -->
        <div class="mt-12 grid grid-cols-2 md:grid-cols-3 lg:grid-cols-5 gap-6">
            <div class="bg-white p-4 rounded-xl shadow-lg text-center floating" onclick="showPlanet('mercury')">
                <div class="w-16 h-16 bg-gray-400 rounded-full mx-auto mb-3"></div>
                <h3 class="font-bold">Mercury</h3>
            </div>
            <div class="bg-white p-4 rounded-xl shadow-lg text-center floating" onclick="showPlanet('venus')">
                <div class="w-16 h-16 bg-yellow-400 rounded-full mx-auto mb-3"></div>
                <h3 class="font-bold">Venus</h3>
            </div>
            <div class="bg-white p-4 rounded-xl shadow-lg text-center floating" onclick="showPlanet('earth')">
                <div class="w-16 h-16 bg-blue-500 rounded-full mx-auto mb-3"></div>
                <h3 class="font-bold">Earth</h3>
            </div>
            <div class="bg-white p-4 rounded-xl shadow-lg text-center floating" onclick="showPlanet('mars')">
                <div class="w-16 h-16 bg-red-500 rounded-full mx-auto mb-3"></div>
                <h3 class="font-bold">Mars</h3>
            </div>
            <div class="bg-white p-4 rounded-xl shadow-lg text-center floating" onclick="showPlanet('jupiter')">
                <div class="w-16 h-16 bg-orange-400 rounded-full mx-auto mb-3"></div>
                <h3 class="font-bold">Jupiter</h3>
            </div>
        </div>
    </main>

    <!-- Footer -->
    <footer class="relative z-10 bg-gradient-to-r from-purple-600 to-indigo-700 text-white p-6 mt-12">
        <div class="container mx-auto text-center">
            <p class="text-lg">Made with ❤️ for kids exploring the universe!</p>
            <p class="mt-2">Click on planets to learn their secrets!</p>
        </div>
    </footer>

    <script>
        // Create stars background
        function createStars() {
            const starsContainer = document.getElementById('stars-container');
            for (let i = 0; i < 200; i++) {
                const star = document.createElement('div');
                star.classList.add('star');
                star.style.left = `${Math.random() * 100}%`;
                star.style.top = `${Math.random() * 100}%`;
                star.style.width = `${Math.random() * 3}px`;
                star.style.height = star.style.width;
                star.style.setProperty('--duration', `${Math.random() * 3 + 2}s`);
                starsContainer.appendChild(star);
            }
        }

        // Initialize solar system
        let animationPlaying = true;
        const planets = [
            { id: 'mercury', size: 12, orbit: 60, speed: 4.15, color: 'gray-400' },
            { id: 'venus', size: 16, orbit: 80, speed: 1.62, color: 'yellow-400' },
            { id: 'earth', size: 18, orbit: 110, speed: 1, color: 'blue-500' },
            { id: 'mars', size: 14, orbit: 140, speed: 0.53, color: 'red-500' },
            { id: 'jupiter', size: 30, orbit: 180, speed: 0.084, color: 'orange-400' },
            { id: 'saturn', size: 24, orbit: 220, speed: 0.034, color: 'yellow-300' },
            { id: 'uranus', size: 20, orbit: 260, speed: 0.012, color: 'blue-300' },
            { id: 'neptune', size: 18, orbit: 300, speed: 0.006, color: 'blue-700' }
        ];

        // Draw orbits
        function drawOrbits() {
            const solarSystem = document.getElementById('solar-system');
            planets.forEach(planet => {
                const orbit = document.createElement('div');
                orbit.className = 'orbit';
                orbit.style.width = `${planet.orbit * 2}px`;
                orbit.style.height = `${planet.orbit * 2}px`;
                orbit.style.top = '50%';
                orbit.style.left = '50%';
                solarSystem.appendChild(orbit);
            });
        }

        // Animate planets
        function animatePlanets() {
            if (!animationPlaying) return;

            const sun = document.getElementById('sun');
            const planetsContainer = document.querySelector('.absolute.top-1/2.left-1/2');

            planets.forEach(planet => {
                const planetElement = document.getElementById(planet.id);
                if (planetElement) {
                    const angle = Date.now() * planet.speed / 1000;
                    const x = Math.cos(angle) * planet.orbit;
                    const y = Math.sin(angle) * planet.orbit;
                    planetElement.style.transform = `translate(${x}px, ${y}px)`;
                    planetElement.style.transition = 'all 0.1s linear';
                }
            });

            requestAnimationFrame(animatePlanets);
        }

        // Toggle animation
        function toggleAnimation() {
            animationPlaying = !animationPlaying;
            const playBtn = document.getElementById('play-btn');
            playBtn.innerHTML = animationPlaying ? 
                '<i class="fas fa-pause mr-2"></i>Pause' : 
                '<i class="fas fa-play mr-2"></i>Play';
            if (animationPlaying) animatePlanets();
        }

        // Reset system
        function resetSystem() {
            const sun = document.getElementById('sun');
            const planetsContainer = document.querySelector('.absolute.top-1/2.left-1/2');
            
            planets.forEach(planet => {
                const planetElement = document.getElementById(planet.id);
                if (planetElement) {
                    planetElement.style.transform = 'translate(0, 0)';
                }
            });
        }

        // Show planet info
        function showPlanet(planetId) {
            const planetInfo = document.getElementById('planet-info');
            
            const planetFacts = {
                sun: {
                    title: "The Sun",
                    description: "The Sun is a star located at the center of our solar system. It's a massive ball of hot gas that gives us light and heat.",
                    funFact: "The Sun makes up about 99.86% of the mass of our solar system!"
                },
                mercury: {
                    title: "Mercury",
                    description: "Mercury is the smallest planet and closest to the Sun. It has no atmosphere and extreme temperature variations.",
                    funFact: "Mercury is so close to the Sun that one year there is only 88 days long!"
                },
                venus: {
                    title: "Venus",
                    description: "Venus is similar in size to Earth but has a thick, toxic atmosphere and is the hottest planet.",
                    funFact: "Venus spins backwards compared to most other planets!"
                },
                earth: {
                    title: "Earth",
                    description: "Earth is our home planet. It's the only known planet to support life, with water, air, and diverse ecosystems.",
                    funFact: "Earth is the only planet that has liquid water on its surface!"
                },
                mars: {
                    title: "Mars",
                    description: "Mars is often called the Red Planet due to iron oxide on its surface. It has the largest volcano in the solar system!",
                    funFact: "Mars has two tiny moons named Phobos and Deimos."
                },
                jupiter: {
                    title: "Jupiter",
                    description: "Jupiter is the largest planet and is a gas giant. It has a giant red spot, which is a storm larger than Earth!",
                    funFact: "Jupiter has at least 79 moons!"
                },
                moon: {
                    title: "The Moon",
                    description: "The Moon is Earth's only natural satellite. It affects ocean tides and has a significant impact on Earth's climate.",
                    funFact: "The Moon is slowly moving away from Earth at a rate of 3.8 centimeters per year!"
                }
            };

            const facts = planetFacts[planetId];
            if (facts) {
                planetInfo.innerHTML = `
                    <h3 class="text-xl font-bold text-blue-600">${facts.title}</h3>
                    <p class="mt-2">${facts.description}</p>
                    <div class="mt-4 bg-blue-100 p-4 rounded-lg">
                        <h4 class="font-bold text-blue-700">Fun Fact:</h4>
                        <p>${facts.funFact}</p>
                    </div>
                `;
            }
        }

        // Initialize everything when page loads
        window.addEventListener('load', () => {
            createStars();
            drawOrbits();
            animatePlanets();
            
            // Add planets to the solar system
            const solarSystem = document.getElementById('solar-system');
            const centerX = solarSystem.offsetWidth / 2;
            const centerY = solarSystem.offsetHeight / 2;
            
            planets.forEach(planet => {
                const planetElement = document.createElement('div');
                planetElement.id = planet.id;
                planetElement.className = `planet w-${planet.size} h-${planet.size} bg-${planet.color} rounded-full shadow-lg floating`;
                planetElement.style.top = '50%';
                planetElement.style.left = '50%';
                solarSystem.appendChild(planetElement);
            });
        });
    </script>
</body>
</html>