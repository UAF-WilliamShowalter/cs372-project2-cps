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

BoundingBox Layered::getCompoundBoundingBox(std::vector<BoundingBox> boxes) {

	double maxHeight = 0, maxWidth = 0;

	for (auto box : boxes) {
		if (maxHeight < box._height)
			maxHeight = box._height;
		if (maxWidth < box._width)
			maxWidth = box._width;
	}

	return BoundingBox(maxWidth, maxHeight);
}