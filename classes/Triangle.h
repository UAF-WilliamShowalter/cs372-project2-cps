// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon
{
public:
	Triangle(double sideLength);
	
private:
	//std::unique_ptr<Polygon> _thePolygon;
};

#endif