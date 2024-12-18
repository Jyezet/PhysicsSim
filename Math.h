#pragma once

double square_root(double);
double power(double, int);
long factorial(long);

class Vector2 {
public:
	double x, y;

	Vector2();
	Vector2(double, double);

	double get_magnitude() const;
	Vector2 get_direction_vector() const;

	friend Vector2 operator +(Vector2, Vector2);
	friend Vector2 operator -(Vector2, Vector2);
	friend void operator +=(Vector2&, Vector2);
	friend void operator -=(Vector2&, Vector2);
	friend double operator *(Vector2, Vector2);
	friend Vector2 operator *(double, Vector2);
	friend Vector2 operator *(Vector2, double);
	friend Vector2 operator /(Vector2, double);
	friend void operator *=(Vector2&, double);
};