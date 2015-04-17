// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// CompoundShape.h

#ifndef COMPOUNDSHAPE_H
#define COMPOUNDSHAPE_H

#include "Shape.h"
#include <initializer_list>
#include <vector>
#include <memory>


class CompoundShape : public Shape
{
public:
	CompoundShape (std::initializer_list<std::shared_ptr<Shape>> shapes):_shapes(shapes)
	{}

	BoundingBox calculateBoundingBox();
	std::string calculatePostScript();

	virtual std::string getBetweenShapePostScript(BoundingBox currentBoundingBox, 
								BoundingBox previousBoundingBox) = 0;

	virtual BoundingBox getCompoundBoundingBox(std::vector<BoundingBox> boxes) = 0;

private:
	std::vector<std::shared_ptr<Shape>> _shapes;
};

#endif