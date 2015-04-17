// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Spacer.h

#ifndef SPACER_H
#define SPACER_H

#include "Shape.h"

class Spacer : public Shape
{
public:
	Spacer(double width, double height);

	BoundingBox calculateBoundingBox();
	std::string calculatePostScript();
	
private:
	double _width, _height;
};

#endif