// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// CompoundShape.cpp

#include "CompoundShape.h"
#include <iostream>

BoundingBox CompoundShape::calculateBoundingBox() {

	std::vector <BoundingBox> boxes;

	for (auto shape : _shapes) {
		boxes.push_back(shape->getBoundingBox());
	}

	return getCompoundBoundingBox(boxes);
}

std::string CompoundShape::calculatePostScript() {
	std::string ps;
	BoundingBox previous;

	for (auto shape : _shapes) {

		if (shape != _shapes[0])
		{ 
			ps += getBetweenShapePostScript(shape->getBoundingBox(),previous);
		}

		previous = shape->getBoundingBox();

		std::string temp = shape->getPostScript();
		temp.erase(0, temp.find("\n") + 1); // first line is translate, get rid of it
		ps += temp;

	}

	return ps;
}