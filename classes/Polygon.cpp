// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Polygon.cpp

#include "Polygon.h"

#include <cmath> // for sin and cos

Polygon::Polygon(int numSides, double sideLength):_numSides(numSides),_sideLength(sideLength)
{
	if(_numSides<1)
	{
		_numSides = 1;
		setBoundingBox(calculateBoundingBox()); // negative sides is bad
	}
	else
	{
		setBoundingBox(calculateBoundingBox());
	}
	
	setPostScript(getBoundingCenterPostScript());
	setPostScript(getDrawBoundingBoxPostScript());
	setPostScript(calculatePostScript());
}

BoundingBox Polygon::calculateBoundingBox()
{
	double x = 0, y = 0, xMin = 0, xMax = 0, yMin = 0, yMax = 0;

	for (double theta = 0.0; theta < 2*PI; theta += 2.0*PI/_numSides)
	{
		x = _sideLength*std::cos(theta)+x;
		y = _sideLength*std::sin(theta)+y;
		if (x > xMax)
			xMax = x;
		if (x < xMin)
			xMin = x;
		if (y > yMax)
			yMax = y;
		if (y < yMin)
			yMin = y;
	}

	return BoundingBox(xMax-xMin,yMax-yMin);
	// TODO: Drawing the bounding box gives slightly different results than this.
}

std::string Polygon::calculatePostScript()
{
	std::stringstream ps;

	ps << "% BEGIN POLYGON\n";

	// save point
	ps << "gsave\n";
	ps << "newpath\n";
	ps << "0 0 moveto\n";

	ps << (int)(-_sideLength/2) << " " << (int)(-getBoundingBox()._height/2) << " rmoveto\n";

	// setup loop of drawing (angles)
	ps << "0 " << (360.0/_numSides) << " 360 {\n";
	
	// setup variables
	ps << "/angle exch def\n";
	
	// draw line
	ps << "angle rotate " << _sideLength << " 0 rlineto\n";

	// fix angle without restore (to avoid loosing currentposition)
	ps << "360 angle sub rotate\n";
	
	// end loop and draw
	ps << "} for stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END POLYGON\n\n";

	return ps.str();
}

