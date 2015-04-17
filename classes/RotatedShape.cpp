// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// RotatedShape.cpp

#include "RotatedShape.h"

RotatedShape::RotatedShape(std::shared_ptr<Shape> rotatedShape, RotationAngle rotationAngle):ShapeDecorator(rotatedShape),_rotationAngle(rotationAngle)
{
	setBoundingBox(calculateBoundingBox());
	setPostScript(getBoundingCenterPostScript());
	//setPostScript(getDrawBoundingBoxPostScript());
	setPostScript(calculatePostScript());
	std::string temp = rotatedShape->getPostScript();
	temp.erase(0, temp.find("\n") + 1); // first line is translate, get rid of it
	setPostScript(temp);
}

BoundingBox RotatedShape::calculateBoundingBox()
{
	BoundingBox boundingBox = getTheShape()->getBoundingBox();

	switch(_rotationAngle)
	{
		case Ninety:
			std::swap(boundingBox._width,boundingBox._height);
			break;

		case OneEighty:
			// do nothing, 180 won't change the height and width
			break;

		case TwoSeventy:
			std::swap(boundingBox._width,boundingBox._height);
			break;

		default:
			// do nothing, RotationAngle enum won't even allow this case
			break;
	}


	return boundingBox;
}

std::string RotatedShape::calculatePostScript()
{
	std::stringstream ps;

	ps << "% BEGIN ROTATE\n";

	ps << _rotationAngle << " rotate\n";

	ps << "% END ROTATE\n";

	return ps.str();
}