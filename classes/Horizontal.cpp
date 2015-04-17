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
		<< "0 " << currentBoundingBox._width/2 + previousBoundingBox._width/2
		<< " translate\n END HORIZONTAL SHAPE MODIFIER\n";
		
	return ps.str();
}
