// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Star.h

#ifndef STAR_H
#define STAR_H

#include "Shape.h"

class Star : public Shape
{
public:
	Star(double sideLength);
	
	virtual BoundingBox calculateBoundingBox();
	virtual std::string calculatePostScript();
private:
	double _sideLength;
};

#endif
