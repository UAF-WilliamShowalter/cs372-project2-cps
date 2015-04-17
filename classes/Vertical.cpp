// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Vertical.cpp

#include "Vertical.h"
#include <sstream>

std::string Vertical::getBetweenShapePostScript(BoundingBox currentBoundingBox, 
		BoundingBox previousBoundingBox) 
{
	std::stringstream ps;
	ps << "\n%VERTICAL SHAPE MODIFIER\n"
		<< "0 " << currentBoundingBox._height/2 + previousBoundingBox._height/2
		<< " translate\n% END VERTICAL SHAPE MODIFIER\n";

	return ps.str();
}

BoundingBox Vertical::getCompoundBoundingBox(std::vector<BoundingBox> boxes) {

	double sumHeight = 0, maxWidth = 0;

	for (auto box : boxes) {
		sumHeight += box._height;
		if (maxWidth < box._width)
			maxWidth = box._width;
	}

	return BoundingBox(maxWidth, sumHeight);
}