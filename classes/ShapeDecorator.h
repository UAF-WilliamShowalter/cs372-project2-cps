// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// ShapeDecorator.h

#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

class ShapeDecorator : public Shape
{
public:
	ShapeDecorator(std::shared_ptr<Shape> decoratedShape);
	virtual ~ShapeDecorator() = default;
	virtual BoundingBox calculateBoundingBox() = 0;
	virtual std::string calculatePostScript() = 0;

	std::shared_ptr<Shape> getTheShape();
	//void setTheShape(std::shared_ptr<Shape> shape);

private:
	std::shared_ptr<Shape> _theShape;
};

#endif