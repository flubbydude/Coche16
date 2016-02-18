
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

struct Vector{

	float magnitude;
	float angle;

	Vector(float magnitude, float angle);
	Vector operator+(Vector& v);
};

#endif
