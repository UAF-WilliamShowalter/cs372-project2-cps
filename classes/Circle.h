// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include <sstream>
using std::stringstream;
#include "Shape.h"

class Circle : public Shape
{
private:
	stringstream _postScriptCode;

public:
	BoundingBox getBoundingBox() { return BoundingBox(); }
	//Coordinate getCoordinate() { return Coordinate(); }
	stringstream getPostScript() { return stringstream(); }
};

#endif