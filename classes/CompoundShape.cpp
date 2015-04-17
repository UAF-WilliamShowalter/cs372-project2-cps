// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// CompoundShape.cpp

#include "CompoundShape.h"
#include <iostream>
#include <sstream>

BoundingBox CompoundShape::calculateBoundingBox() {

	return getCompoundBoundingBox(_shapes);
}

std::string CompoundShape::calculatePostScript() {
	std::stringstream ps;
	BoundingBox previous;

//	ps << (int)(-getBoundingBox()._width/2) << " " << (int)(-getBoundingBox()._height/2) << " translate \n";
	auto first = _shapes[0];
	for (auto shape : _shapes) 
	{
		//ps << "\ngsave\n";
		if (shape != _shapes[0])
		{ 
			ps << getBetweenShapePostScript(shape->getBoundingBox(),previous);
		}

		previous = shape->getBoundingBox();

		std::string temp = shape->getPostScript();
		temp.erase(0, temp.find("\n") + 1); // first line is translate, get rid of it
		ps << temp;
		//ps << "\ngrestore\n";

	}

	return ps.str();
}