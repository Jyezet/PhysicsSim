#include "Electromagnetism.h"

ElectricField::ElectricField(){}

ElectricField::ElectricField(double charge, Vector2 origin) {
	this->charge = charge;
	this->origin = origin;
}

Vector2 ElectricField::calculate(Vector2 position) const {
	double DistanceSquared = (this->origin - position).get_magnitude();
	Vector2 UnitVector = (position - this->origin).get_direction_vector();

	return UnitVector * (this->charge / DistanceSquared);
}

void ElectricField::move_origin(Vector2 new_origin) {
	this->origin = new_origin;
}

CompositeElectricField::CompositeElectricField(std::vector<ElectricField*> electric_fields) {
	this->electric_fields = electric_fields;
}

Vector2 CompositeElectricField::calculate(Vector2 Position) const {
	Vector2 Result;
	for (int i = 0; i < this->electric_fields.size(); i++) {
		Result += this->electric_fields[i]->calculate(Position);
	}

	return Result;
}