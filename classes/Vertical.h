// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Vertical.h

#ifndef VERTICALSHAPE_H
#define VERTICALSHAPE_H

#include "CompoundShape.h"
#include <initializer_list>
#include <vector>
#include <memory>


class Vertical : public CompoundShape
{
public:
	Vertical (std::initializer_list<std::shared_ptr<Shape>> shapes):CompoundShape(shapes)
	{
		setBoundingBox(calculateBoundingBox());
		setPostScript(calculatePostScript());
	}

	BoundingBox getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> shapes);
	std::string getBetweenShapePostScript(BoundingBox currentBoundingBox, BoundingBox previousBoundingBox);
};

#endif