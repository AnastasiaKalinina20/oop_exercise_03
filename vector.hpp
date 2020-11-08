#pragma once

#include <iostream>
#include <cmath>

class Vector{
public: 
	double x;
	double y;
	double length;

	void setup(double x1, double y1, double x2, double y2){
		x = x2 - x1;
		y = y2 - y1;
		length = sqrt(pow(x, 2) + pow(y, 2));
	}

	bool perpendicular(Vector second){
		if(x * second.x + y * second.y){
			return false;
		} else return true;
	}
};