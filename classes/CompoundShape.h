// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// CompoundShape.h

#ifndef COMPOUNDSHAPE_H
#define COMPOUNDSHAPE_H

#include "Shape.h"

class CompoundShape : public Shape
{
private:
	
public:
	BoundingBox getBoundingBox() { return BoundingBox(); }
	//Coordinate getCoordinate() { return Coordinate(); }
	stringstream getPostScript() { return stringstream(); }
};

#endif