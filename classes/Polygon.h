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
	Polygon(double numSides, double sideLength):_numSides(numSides),_sideLength(sideLength)
	{
		setHeightWidth(numSides, sideLength);
	}
	virtual ~Polygon() = default; // Triangle and Square derived
	BoundingBox getBoundingBox() { return BoundingBox(); }
	Coordinate getCoordinate() { return Coordinate(); }
	stringstream getPostScript();

private:
	double _numSides;
	double _sideLength;
	void setHeightWidth(double numSides, double sideLength);
	BoundingBox _boundingBox;
	//Coordinate _currentCoordinate;
	stringstream _postScriptCode;
	
};

#endif
