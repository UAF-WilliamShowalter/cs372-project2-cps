// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double radius);

	BoundingBox calculateBoundingBox();
	std::string calculatePostScript();

private:
	double _radius;
};

#endif