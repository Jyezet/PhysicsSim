#pragma once
#include "Math.h"
#include <vector>

class ElectricField {
	double charge;
	Vector2 origin;
public:
	ElectricField();
	ElectricField(double, Vector2);
	Vector2 calculate(Vector2) const;
	void move_origin(Vector2);
};

class CompositeElectricField {
	std::vector<ElectricField*> electric_fields;
public:
	CompositeElectricField(std::vector<ElectricField*>);
	Vector2 calculate(Vector2) const;
};