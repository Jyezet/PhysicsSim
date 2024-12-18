#include <SFML/Graphics.hpp>
#include <vector>

#include "Math.h"
#include "Electromagnetism.h"
#include "Particles.h"

#define WINDOW_TITLE "Nuclear simulation"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(60);
    sf::Event e;
    sf::Clock clock;
    float dt;

    Particle proton("Proton", 1, sf::Color::Red, 20);
    Particle neutron("Neutron", 0, sf::Color::Green, 10);
    Particle electron("Electron", -1, sf::Color::Blue, 5);

    // obviously these are not the actual values
    proton.mass = 50;
    neutron.mass = 50;
    electron.mass = 50;

    std::vector<Particle> particles = { Particle(proton), Particle(electron) };
    particles[0].position = Vector2(100, 100);
    particles[1].position = Vector2(200, 200);

    CompositeElectricField total_electric_field({
        &particles[0].electric_field,
        &particles[1].electric_field
    });

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

        // Calculate this first before moving anything
        for (int i = 0; i < particles.size(); i++)
            particles[i].acceleration = 500 * particles[i].charge * total_electric_field.calculate(particles[i].position);

        for (int i = 0; i < particles.size(); i++) {
            particles[i].move(dt);
            window.draw(particles[i].shape);
        }

        window.display();
    }

    return 0;
}