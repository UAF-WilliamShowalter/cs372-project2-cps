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
	Rectangle(double width, double height)
	{
		_boundingBox._width=width;
		_boundingBox._height=height;
	}
	BoundingBox getBoundingBox() { return BoundingBox(); }
	Coordinate getCoordinate() { return Coordinate(); }
	stringstream getPostScript();

private:
	stringstream _postScriptCode;
	BoundingBox _boundingBox;
	//Coordinate _currentCoordinate;
};

#endif