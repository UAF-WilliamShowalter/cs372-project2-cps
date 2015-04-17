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

BoundingBox Vertical::getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> & shapes) {

	double sumHeight = 0, maxWidth = 0;

	for (auto shape : shapes) {

		sumHeight += shape->getBoundingBox()._height;
		if (maxWidth < shape->getBoundingBox()._width)
			maxWidth = shape->getBoundingBox()._width;
	}

	auto newCenterX = getBoundingBox()._center._x;
	auto newCenterY = getBoundingBox()._center._y - sumHeight/2;

/*	auto shapeFirst = shapes[0]; 
	shapeFirst->setCenter(Coordinate(newCenterY - sumHeight + shapeFirst->getBoundingBox()._height/2,newCenterY));

	auto previousShape = shapeFirst;

	for (auto shape : shapes) {
		if (shape != shapes[0]) {
			auto currentX = shape->getBoundingBox()._center._x;
			auto currentY = shape->getBoundingBox()._center._y;
			auto newX = currentX + previousShape->getBoundingBox()._width/2 
							+ shape->getBoundingBox()._width/2;
			shape->setCenter(Coordinate(newX,currentY));
		}
		previousShape = shape;
	}
*/

	return BoundingBox(maxWidth, sumHeight, Coordinate(newCenterX, newCenterY));
}