#pragma once
#include "Math.h"
#include "Electromagnetism.h"
#include <SFML/Graphics.hpp>

class Particle {
public:
	const char* name;
	double charge;
	double mass;
	Vector2 position, velocity, acceleration;
	sf::CircleShape shape;
	ElectricField electric_field;

	Particle();
	Particle(const char*, double, sf::Color, int);
	Particle(const char*, double, Vector2);
	void move(float);
};