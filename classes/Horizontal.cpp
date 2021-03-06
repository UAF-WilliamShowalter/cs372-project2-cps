// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Horizontal.cpp

#include "Horizontal.h"
#include <sstream>

std::string Horizontal::getBetweenShapePostScript(BoundingBox currentBoundingBox,
		BoundingBox previousBoundingBox)
{
	// NOT USED
	std::stringstream ps;
	ps << "\n%HORIZONTAL SHAPE MODIFIER\n"
		<< currentBoundingBox._width/2 + previousBoundingBox._width/2 << " 0"
		<< " translate\n% END HORIZONTAL SHAPE MODIFIER\n";

	return ps.str();
}

BoundingBox Horizontal::getCompoundBoundingBox(std::vector<std::shared_ptr<Shape>> shapes) {

	double maxHeight = 0, sumWidth = 0;

	for (auto shape : shapes) {

		sumWidth += shape->getBoundingBox()._width;
		if (maxHeight < shape->getBoundingBox()._height)
			maxHeight = shape->getBoundingBox()._height;
	}

	auto newCenterX = getBoundingBox()._center._x;
	auto newCenterY = getBoundingBox()._center._y;

	auto shapeFirst = shapes[0];
	shapeFirst->setCenter(Coordinate(newCenterX - sumWidth/2 + shapeFirst->getBoundingBox()._width/2,newCenterY));
	shapeFirst->replacePostScript("%NEW TRANSLATE FIRST\n" + 
		shapeFirst->getBoundingCenterPostScript() + shapeFirst->getDrawBoundingBoxPostScript() + shapeFirst->calculatePostScript());

	auto previousShape = shapeFirst;

	for (auto shape : shapes) {
		if (shape.get() != shapes[0].get()) {
			auto currentX = shape->getBoundingBox()._center._x;
			auto currentY = shape->getBoundingBox()._center._y;
			//auto newX = currentX + previousShape->getBoundingBox()._width/2
			//				+ shape->getBoundingBox()._width/2;
			auto newX = previousShape->getBoundingBox()._center._x +
						previousShape->getBoundingBox()._width/2 +
						shape->getBoundingBox()._width/2;
			shape->setCenter(Coordinate(newX,newCenterY));
			shape->replacePostScript("%NEW TRANSLATE\n" + 
				shape->getBoundingCenterPostScript() + shape->getDrawBoundingBoxPostScript() + shape->calculatePostScript());
		}
		previousShape = shape;
	}
	return BoundingBox(sumWidth, maxHeight, Coordinate(newCenterX, newCenterY));
}