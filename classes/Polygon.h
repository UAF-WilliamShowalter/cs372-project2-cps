// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Polygon.h

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape
{
private:
	void setHeightWidth(double numSides, double sideLength);
	BoundingBox _boundingBox;
	Coordinate _currentCoordinate;
	stringstream _postScriptCode;

public:
	virtual ~Polygon() = default;
};

#endif
