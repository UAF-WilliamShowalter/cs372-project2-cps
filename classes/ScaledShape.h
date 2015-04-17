// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// ScaledShape.h

#ifndef SCALEDSHAPE_H
#define SCALEDSHAPE_H

#include "ShapeDecorator.h"

class ScaledShape : public ShapeDecorator
{
public:
	ScaledShape(std::shared_ptr<Shape> scaledShape, double fx, double fy);
	virtual BoundingBox calculateBoundingBox();
	virtual std::string calculatePostScript();

private:
	double _fx, _fy;
};

#endif