#pragma once
#include <_Math.h>
#include <vector>

#ifndef WINDOW_TITLE
#define WINDOW_TITLE "Nuclear simulation"
#endif

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 800
#endif

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
	CompositeElectricField();
	CompositeElectricField(std::vector<ElectricField*>);
	Vector2 calculate(Vector2) const;
};