// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon.h"

class Square : public Polygon
{
public:
	Square(double sideLength);
	
private:
	//std::unique_ptr<Polygon> _thePolygon;
};

#endif