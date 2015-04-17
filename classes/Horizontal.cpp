// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Horizontal.cpp

#include "Horizontal.h"
#include <sstream>

std::string Horizontal::getBetweenShapePostScript(BoundingBox currentBoundingBox, 
		BoundingBox previousBoundingBox) 
{
	std::stringstream ps;
	ps << "\n%HORIZONTAL SHAPE MODIFIER\n"
		<< currentBoundingBox._width/2 + previousBoundingBox._width/2 << " 0"
		<< " translate\n% END HORIZONTAL SHAPE MODIFIER\n";
		
	return ps.str();
}

BoundingBox Horizontal::getCompoundBoundingBox(std::vector<BoundingBox> boxes) {

	double maxHeight = 0, sumWidth = 0;

	for (auto box : boxes) {
		sumWidth += box._width;
		if (maxHeight < box._height)
			maxHeight = box._height;
	}

	return BoundingBox(sumWidth, maxHeight);
}