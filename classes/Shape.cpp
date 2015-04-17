// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.cpp

#include "Shape.h"

/*
Shape::Shape()
{
	
}
*/

BoundingBox Shape::getBoundingBox()
{
	return _boundingBox;
}

std::string Shape::getPostScript()
{
	return _postScriptCode;
}

void Shape::setBoundingBox(BoundingBox boundingBox)
{
	_boundingBox = boundingBox;
}

void Shape::setPostScript(std::string postScriptCode)
{
	_postScriptCode += postScriptCode; // stringstreams aren't copyable
}

std::string Shape::getBoundingCenterPostScript()
{
	std::stringstream ps;
	ps << getBoundingBox()._center._x << " " << getBoundingBox()._center._y << " translate\n";
	return ps.str();
}

std::string Shape::getDrawBoundingBoxPostScript()
{
	std::stringstream ps;

	ps << "% BEGIN BOUNDINGBOX\n";

	// save point
	ps << "gsave\n";
	ps << "newpath\n";
	ps << "0 0 moveto\n";

	ps << (int)(-getBoundingBox()._width/2) << " " << (int)(-getBoundingBox()._height/2) << " rmoveto\n";
	
	// draw rectangle
	ps << "0 " << (int)(getBoundingBox()._height) << " rlineto\n";
	ps << (int)(getBoundingBox()._width) << " 0 rlineto\n";
	ps << "0 " << (int)(-getBoundingBox()._height) << " rlineto\n";
	ps << (int)(-getBoundingBox()._width) << " 0 rlineto\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END BOUNDINGBOX\n\n";

	return ps.str();
}

void Shape::setCenter(Coordinate newCenter){
	_boundingBox._center = newCenter;
}
