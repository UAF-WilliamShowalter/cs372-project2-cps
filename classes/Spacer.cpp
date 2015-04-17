// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Spacer.cpp

#include "Spacer.h"

Spacer::Spacer(double width, double height):_width(width),_height(height)
{
	setBoundingBox(calculateBoundingBox());
	setPostScript(getBoundingCenterPostScript());
	setPostScript(getDrawBoundingBoxPostScript());
	setPostScript(calculatePostScript());
}

BoundingBox Spacer::calculateBoundingBox()
{
	return BoundingBox(_width,_height);
}

std::string Spacer::calculatePostScript()
{
	std::stringstream ps;

	ps << "% BEGIN SPACER\n";

	// save point
	ps << "gsave\n";
	ps << "newpath\n";
	ps << "0 0 moveto\n";
	
	// setup starting point of shape (relative)
	// TODO: this could be a helper function of Shape: moveToStartDraw()
	// virtual, not pure virtual (polygon does something different)
	// circle doesn't move
	ps << (int)(-getBoundingBox()._width/2) << " " << (int)(-getBoundingBox()._height/2) << " rmoveto\n";
	
	// draw rectangle
	ps << "0 " << (int)(getBoundingBox()._height) << " rlineto\n";
	ps << (int)(getBoundingBox()._width) << " 0 rlineto\n";
	ps << "0 " << (int)(-getBoundingBox()._height) << " rlineto\n";
	ps << (int)(-getBoundingBox()._width) << " 0 rlineto\n";
	ps << "closepath\n";

	// restore point
	ps << "grestore\n";

	ps << "% END SPACER\n\n";

	return ps.str();
}

