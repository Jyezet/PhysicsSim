#include "Math.h"

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

double Vector2::get_magnitude() const {
	return square_root(x * x + y * y);
}

Vector2 Vector2::get_direction_vector() const {
	return *this / this->get_magnitude();
}

// Summing
Vector2 operator +(Vector2 v1, Vector2 v2) {
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

void operator +=(Vector2& v1, Vector2 v2) {
	v1 = v1 + v2;
}

// Substracting
Vector2 operator -(Vector2 v1, Vector2 v2) {
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

void operator -=(Vector2& v1, Vector2 v2) {
	v1 = v1 - v2;
}

// Dot product
double operator *(Vector2 v1, Vector2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

// Scaling
Vector2 operator *(double n, Vector2 v) {
	return Vector2(n * v.x, n * v.y);
}

Vector2 operator /(Vector2 v, double n) {
	return Vector2(v.x / n, v.y / n);
}

// Scaling made commutative
Vector2 operator *(Vector2 v, double n) {
	return Vector2(n * v.x, n * v.y);
}

void operator *=(Vector2& v, double n) {
	v = n * v;
}

// Math functions
double square_root(double n) {
	// Heron's method
	const double x0 = 1;
	const int iterations = 20;

	double res = x0;

	for (int i = 0; i < iterations; i++) {
		res = 0.5 * (res + n / res);
	}

	return res;
}

double power(double x, int exp) {
	double result = 1;
	bool invert = false;

	if (exp == 0) return 1;
	if (exp == 1) return x;
	if (exp < 0) {
		exp *= -1;
		invert = true;
	}

	for (int i = 0; i < exp; i++) {
		result *= x;
	}

	if (invert) result = 1 / result;
	return result;
}

long factorial(long x) {
	if (x > 31) throw;
	if (x == 0) return 1;
	return x * factorial(x - 1);
}