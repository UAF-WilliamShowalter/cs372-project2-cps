// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.cpp

#include "Shape.h"

Shape::Shape()
{
	setBoundingBox(calculateBoundingBox());
	setPostScript(appendPostScript());
}

BoundingBox Shape::getBoundingBox()
{
	return _boundingBox;
}

std::string Shape::getPostScript()
{
	return _postScriptCode.str();
}

void Shape::setBoundingBox(BoundingBox boundingBox)
{
	_boundingBox = boundingBox;
}

void Shape::setPostScript(std::stringstream postScriptCode)
{
	_postScriptCode << postScriptCode.str(); // string streams aren't copyable
}

BoundingBox Shape::calculateBoundingBox()
{
	return getBoundingBox();
}

std::stringstream Shape::appendPostScript()
{
	std::stringstream ps(getPostScript());

	ps << "%!\n";
	ps << "% BEGIN SHAPE\n";

	ps << getBoundingBox()._center._x << " " << getBoundingBox()._center._y << " translate\n";
	
	ps << "% END SHAPE\n\n";

	return ps;
}

