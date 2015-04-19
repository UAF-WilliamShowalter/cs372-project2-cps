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

	auto first = _shapes[0];
	for (auto shape : _shapes) 
	{
		ps<<"%Compound before start shape\ngsave\n";

		previous = shape->getBoundingBox();

		ps << shape->getPostScript();
		ps << "\ngrestore\n";

	}

	return ps.str();
}

std::string CompoundShape::getBoundingCenterPostScript() {

	// Something different can be done here to translate the  compound shape correctly.
	// Not sure what. 
	// Ideally 
	std::stringstream ps;
	ps << "%getBoundingCenterPostScript\n";
	ps << getBoundingBox()._center._x << " " << getBoundingBox()._center._y << " translate\n";

	return ps.str();
}
