// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// ShapeDecorator.h

#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

class ShapeDecorator
{
public:
	

private:
	std::unique_ptr<Shape> _theShape;
};

#endif