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
