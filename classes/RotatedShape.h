// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// RotatedShape.h

#ifndef ROTATEDSHAPE_H
#define ROTATEDSHAPE_H

#include "ShapeDecorator.h"
#include <algorithm> // for swap

enum RotationAngle { Ninety = 90, OneEighty = 180, TwoSeventy = 270 };

class RotatedShape : public ShapeDecorator
{
public:
	RotatedShape(std::shared_ptr<Shape> rotatedShape, RotationAngle rotationAngle);
	virtual BoundingBox calculateBoundingBox();
	virtual std::string calculatePostScript();

private:
	RotationAngle _rotationAngle;
};

#endif