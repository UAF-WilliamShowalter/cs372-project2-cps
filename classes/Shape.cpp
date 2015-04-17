// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.cpp

#include "Shape.h"

/*
Shape::Shape()
{
	//setBoundingBox(calculateBoundingBox());
	//setPostScript(calculatePostScript());
}
*/

BoundingBox Shape::getBoundingBox()
{
	return _boundingBox;
}

std::string Shape::getPostScript()
{
	return _postScriptCode.str(); // stringstreams are not returnable
}

void Shape::setBoundingBox(BoundingBox boundingBox)
{
	_boundingBox = boundingBox;
}

void Shape::setPostScript(std::stringstream postScriptCode)
{
	_postScriptCode << postScriptCode.str(); // stringstreams aren't copyable
}

/*
BoundingBox Shape::calculateBoundingBox()
{
	return getBoundingBox();
}

std::stringstream Shape::calculatePostScript()
{
	std::stringstream ps(getPostScript());

	ps << "%!\n";
	ps << "% BEGIN SHAPE\n";

	ps << getBoundingBox()._center._x << " " << getBoundingBox()._center._y << " translate\n";
	
	ps << "% END SHAPE\n\n";

	ps << drawBoundingBox().str();

	return ps;
}
*/

std::stringstream Shape::getBoundingCenterPostScript()
{
	std::stringstream ps;
	ps << getBoundingBox()._center._x << " " << getBoundingBox()._center._y << " translate\n";
	return ps;
}

std::stringstream Shape::getDrawBoundingBoxPostScript()
{
	std::stringstream ps; // put the old postscript code in first

	ps << "% BEGIN BOUNDINGBOX\n";

	// save point
	ps << "gsave\n";
	ps << "newpath\n";
	ps << "0 0 moveto\n";

	ps << (int)(-getBoundingBox()._width/2) << " " << (int)(-getBoundingBox()._height/2) << " rmoveto\n";
	
	// draw rectangle
	ps << "0 " << (int)(getBoundingBox()._width) << " rlineto\n";
	ps << (int)(getBoundingBox()._height) << " 0 rlineto\n";
	ps << "0 " << (int)(-getBoundingBox()._width) << " rlineto\n";
	ps << (int)(-getBoundingBox()._height) << " 0 rlineto\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END BOUNDINGBOX\n\n";

	return ps;
}


