// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Circle.h

#include "Circle.h"

Circle::Circle(double radius):_radius(radius)
{
	setBoundingBox(calculateBoundingBox());
	setPostScript(getBoundingCenterPostScript());
	setPostScript(getDrawBoundingBoxPostScript());
	setPostScript(calculatePostScript());
}

BoundingBox Circle::calculateBoundingBox()
{
	return BoundingBox(_radius,_radius);
}

std::string Circle::calculatePostScript()
{
	std::stringstream ps;//(getPostScript()); // put the old postscript code in first

	ps << "% BEGIN CIRCLE\n";

	// save point
	ps << "gsave\n";
	ps << "0 0 moveto\n";
	ps << "newpath\n";
	
	// draw circle
	ps << "0 0 " << (int)(getBoundingBox()._width/2) << " 0 360 arc\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END CIRCLE\n\n";

	return ps.str();
}

