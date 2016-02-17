/*
 * Vector
 *
 *  Created on: Jan 21, 2016
 *      Author: Steven
 */

#ifndef VECTOR_H
#define VECTOR_H

struct Vector{

	float magnitude;
	float angle;

	Vector(float magnitude, float angle): magnitude(magnitude), angle(angle) {}
	Vector* operator+(Vector* v);
};

#endif
