#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <iomanip>

#include <_Math.h>
//#include "Electromagnetism/Electromagnetism.h"
//#include "Electromagnetism/Particles.h"
//#include "Electromagnetism/Sim.h"

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#endif
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 800
#endif
#ifndef WINDOW_TITLE
#define WINDOW_TITLE "Sim"
#endif

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(60);
    sf::Event e;
    sf::Clock clock;
    float dt;

    /*Particle proton("Proton", 1, sf::Color::Red, 20, 100);
    Particle neutron("Neutron", 0, sf::Color::Green, 10, 20);
    Particle electron("Electron", -1, sf::Color::Blue, 5, 5);
     
    proton.position = Vector2(100, 100);
    neutron.position = Vector2(150, 150);
    electron.position = Vector2(400, 400);

    ElectromagnetismSim sim(std::vector<Particle*>{ &proton, &electron, &neutron }, &window);*/

    while (window.isOpen()) {
        while (window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        dt = clock.restart().asSeconds();
        
        window.clear();

        //sim.mainloop(dt);

        window.display();
    }

    return 0;
}