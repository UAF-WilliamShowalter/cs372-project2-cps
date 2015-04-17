// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Layered.h

#ifndef LAYEREDSHAPE_H
#define LAYEREDSHAPE_H

#include "CompoundShape.h"
#include <initializer_list>
#include <vector>
#include <memory>


class Layered : public CompoundShape
{
public:
	Layered (std::initializer_list<std::shared_ptr<Shape>> shapes):CompoundShape(shapes)
	{
		setBoundingBox(calculateBoundingBox());
		setPostScript(getBoundingCenterPostScript());
		setPostScript(getDrawBoundingBoxPostScript());
		setPostScript(calculatePostScript());
	}

	std::string getBetweenShapePostScript(BoundingBox currentBoundingBox, BoundingBox previousBoundingBox);
};

#endif