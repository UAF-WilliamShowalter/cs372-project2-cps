// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// ShapeDecorator.cpp

#include "ScaledShape.h"

ScaledShape::ScaledShape(std::shared_ptr<Shape> scaledShape, double fx, double fy):ShapeDecorator(scaledShape),_fx(fx),_fy(fy)
{
	setBoundingBox(calculateBoundingBox()); // set the bounding box to the new shape
	setPostScript(getBoundingCenterPostScript()); // translate said bounding box to the center
	//setPostScript(getDrawBoundingBoxPostScript()); // put in postscript to draw bounding box
	setPostScript(calculatePostScript()); // apply the decorator (which is translated)
	
	std::string temp = scaledShape->getPostScript();
	temp.erase(0, temp.find("\n") + 1); // first line is translate, get rid of it
	
	setPostScript(temp); // apply the new non-translated decorator
	
}

BoundingBox ScaledShape::calculateBoundingBox()
{
	BoundingBox boundingBox = getTheShape()->getBoundingBox();

	boundingBox._width *= _fx;
	boundingBox._height *= _fy;

	return boundingBox;
}

std::string ScaledShape::calculatePostScript()
{
	std::stringstream ps;

	ps << "% BEGIN SCALE\n";

	ps << _fx << " " << _fy << " scale\n";

	ps << "% END SCALE\n";

	return ps.str();
}