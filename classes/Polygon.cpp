// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Polygon.cpp

#include "Polygon.h"

#include <cmath>
using std::sin;
using std::cos;

Polygon::Polygon(int numSides, double sideLength):_numSides(numSides),_sideLength(sideLength)
{
	if(numSides<1)
	{
		_numSides = 1;
		setBoundingBox(calculateBoundingBox(_numSides,sideLength)); // default to a triangle
	}
	else
	{
		setBoundingBox(calculateBoundingBox(numSides,sideLength));
	}
	
	setPostScript(appendPostScript());
}

BoundingBox Polygon::calculateBoundingBox(int numSides, double sideLength)
{
	double x = 0, y = 0, xMin = 0, xMax = 0, yMin = 0, yMax = 0;

	for (double theta = 0.0; theta < 2*PI; theta += 2.0*PI/numSides)
	{
		x = sideLength*cos(theta)+x;
		y = sideLength*sin(theta)+y;
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
	// TODO: Drawing the bounding box gives different results than this...
}

std::stringstream Polygon::appendPostScript()
{
	std::stringstream ps(getPostScript()); // put the old postscript code in first

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
	ps << "angle rotate " << _sideLength << " 0 " << " rlineto\n";

	// fix angle without restore (to avoid loosing currentposition)
	ps << "360 angle sub rotate\n";
	
	// end loop and draw
	ps << "} for stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END POLYGON\n\n";

	ps << drawBoundingBox().str();

	return ps;
}

