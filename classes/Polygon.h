// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Polygon.h

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape
{
public:
	Polygon(int numSides, double sideLength);
	virtual ~Polygon() = default; // triangle and square are derived from polygon
	
	virtual BoundingBox calculateBoundingBox(int numSides, double sideLength);
	virtual std::stringstream appendPostScript();
private:
	int _numSides;
	double _sideLength;
};

#endif
