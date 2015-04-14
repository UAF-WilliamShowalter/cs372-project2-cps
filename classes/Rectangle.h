// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double width, double height);

	BoundingBox calculateBoundingBox();
	std::stringstream appendPostScript();

private:
	double _width, _height;
};

#endif