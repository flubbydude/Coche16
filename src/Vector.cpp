#include "Vector.h"
#include <Math.h>

Vector Vector::operator+(Vector& v){
	float x1 = magnitude*cos(angle);
	float y1 = magnitude*sin(angle);
	float x2 = v.magnitude*cos(v.angle);
	float y2 = v.magnitude*sin(v.angle);
	float xTotal = x1+x2;
	float yTotal = y1+y2;
	float degrees = atan2(yTotal,xTotal);
	float magnitude = sqrt(xTotal*xTotal+yTotal*yTotal);
	return Vector(magnitude, degrees);
}
