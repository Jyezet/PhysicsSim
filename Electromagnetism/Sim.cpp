#include "Sim.h"

ElectromagnetismSim::ElectromagnetismSim(std::vector<Particle*> particles, sf::RenderWindow* context) {
    this->particles = particles;
    this->ctx = context;
    std::vector<ElectricField*> electric_fields;

    for (int i = 0; i < this->particles.size(); i++) {
        electric_fields.push_back(&this->particles[i]->electric_field);
    }

    this->total_electric_field = CompositeElectricField(electric_fields);
}

void ElectromagnetismSim::mainloop(float dt) {
    for (int i = 0; i < particles.size(); i++)
        particles[i]->acceleration = 500 * particles[i]->charge * total_electric_field.calculate(particles[i]->position);

    for (int i = 0; i < particles.size(); i++) {
        particles[i]->move(dt);
        this->ctx->draw(particles[i]->shape);
    }
}