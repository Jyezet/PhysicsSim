#pragma once
#include "Particles.h"
#include <vector>

class ElectromagnetismSim {
	std::vector<Particle*> particles;
	sf::RenderWindow* ctx;
	CompositeElectricField total_electric_field;
public:
	ElectromagnetismSim(std::vector<Particle*>, sf::RenderWindow*);
	void mainloop(float);
};