/*
 * Vector
 *
 *  Created on: Jan 21, 2016
 *      Author: Steven
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

struct Vector{

	float magnitude;
	float angle;

	Vector(float magnitude, float angle): magnitude(magnitude), angle(angle) {
		while(angle >= 2 * M_PI) {
			angle -= 2 * M_PI;
		}

		while(angle <= 0) {
			angle += 2 * M_PI;
		}
	}
};

#endif
