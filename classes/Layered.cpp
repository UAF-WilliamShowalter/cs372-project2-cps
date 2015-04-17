// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Layered.cpp

#include "Layered.h"
#include <sstream>

std::string Layered::getBetweenShapePostScript(BoundingBox currentBoundingBox, 
		BoundingBox previousBoundingBox) 
{
	std::stringstream ps;
	ps << "\n%LAYERED SHAPE MODIFIER NONE\n";
	return ps.str();
}

BoundingBox Layered::getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> shapes) {

	double maxHeight = 0, maxWidth = 0;

	for (auto shape : shapes) {
		if (maxHeight < shape->getBoundingBox()._height)
			maxHeight = shape->getBoundingBox()._height;
		if (maxWidth < shape->getBoundingBox()._width)
			maxWidth = shape->getBoundingBox()._width;
	}

	return BoundingBox(maxWidth, maxHeight);
}