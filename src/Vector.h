
#ifndef VECTOR_H
#define VECTOR_H

struct Vector{

	float magnitude;
	float angle;

	Vector(float magnitude, float angle): magnitude(magnitude), angle(angle) {}
	Vector operator+(Vector& v);
};

#endif
