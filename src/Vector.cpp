/*
 * Vector.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: Benjamin
 */

#include "Vector.h"
#include <Math.h>

/*
Vector* Vector::operator+(Vector* v){
	float x1 = this->magnitude*cos(this->angle);
	float y1 = this->magnitude*sin(this->angle);
	float x2 = v->magnitude*cos(v->angle);
	float y2 = v->magnitude*sin(v->angle);
	float xTotal = x1+x2;
	float yTotal = y1+y2;
	float degrees = atan2(yTotal,xTotal);
	float magnitude = sqrt(xTotal*xTotal+yTotal*yTotal);
	return new Vector(magnitude, degrees);
}
*/
