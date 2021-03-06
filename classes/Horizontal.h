// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Horizontal.h

#ifndef HORIZONTALSHAPE_H
#define HORIZONTALSHAPE_H

#include "CompoundShape.h"
#include <initializer_list>
#include <vector>
#include <memory>


class Horizontal : public CompoundShape
{
public:
	Horizontal (std::initializer_list<std::shared_ptr<Shape>> shapes):CompoundShape(shapes)
	{
		setBoundingBox(calculateBoundingBox());
		//setPostScript(getBoundingCenterPostScript());
		//setPostScript(getDrawBoundingBoxPostScript());
		setPostScript(calculatePostScript());
	}

	BoundingBox getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> shapes);
	std::string getBetweenShapePostScript(BoundingBox currentBoundingBox, BoundingBox previousBoundingBox);
};

#endif