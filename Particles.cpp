#include "Particles.h"

Particle::Particle() {}

Particle::Particle(const char* name, double charge, Vector2 position) {
	this->name = name;
	this->charge = charge;
	this->position = position;
	this->electric_field = ElectricField(this->charge, this->position);
}

Particle::Particle(const char* name, double charge, sf::Color color, int radius) {
	this->name = name;
	this->charge = charge;
	this->electric_field = ElectricField(this->charge, this->position);
	this->shape = sf::CircleShape(radius);
	this->shape.setFillColor(color);
}

void Particle::move(float dt) {
	this->position += 0.5 * this->acceleration * power(dt, 2) + this->velocity * dt; // Motion equation
	this->velocity += this->acceleration * dt;
	this->shape.setPosition(this->position.x, this->position.y);
	this->electric_field.move_origin(this->position);
}