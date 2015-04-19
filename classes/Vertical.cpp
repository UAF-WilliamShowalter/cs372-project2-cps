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

BoundingBox Vertical::getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> shapes) {
// Everything needs refactored
// This all needs changed

	double sumHeight = 0, maxWidth = 0;

	for (auto shape : shapes) {

		sumHeight += shape->getBoundingBox()._height;
		if (maxWidth < shape->getBoundingBox()._width)
			maxWidth = shape->getBoundingBox()._width;
	}

	auto newCenterX = getBoundingBox()._center._x;
	auto newCenterY = getBoundingBox()._center._y;

	auto shapeFirst = shapes[0];
	shapeFirst->setCenter(Coordinate(newCenterX, newCenterY - sumHeight/2 + shapeFirst->getBoundingBox()._height/2));
	shapeFirst->replacePostScript("%NEW TRANSLATE FIRST\n" + 
		shapeFirst->getBoundingCenterPostScript() + shapeFirst->getDrawBoundingBoxPostScript() + shapeFirst->calculatePostScript());

	auto previousShape = shapeFirst;

	for (auto shape : shapes) {
		if (shape.get() != shapes[0].get()) {
			auto currentX = shape->getBoundingBox()._center._x;
			auto currentY = shape->getBoundingBox()._center._y;

			auto newY = previousShape->getBoundingBox()._center._y +
						previousShape->getBoundingBox()._height/2 +
						shape->getBoundingBox()._height/2;

			shape->setCenter(Coordinate(newCenterX,newY));
			shape->replacePostScript("%NEW TRANSLATE\n" + 
				shape->getBoundingCenterPostScript() + shape->getDrawBoundingBoxPostScript() + shape->calculatePostScript());
		}
		previousShape = shape;
	}

	return BoundingBox(maxWidth, sumHeight, Coordinate(newCenterX, newCenterY));
}