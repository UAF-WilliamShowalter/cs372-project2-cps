// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Polygon.cpp

#include "Polygon.h"
#include <cmath>

using std::sin;
using std::cos;

void Polygon::setHeightWidth(double numSides, double sideLength)
{
	double x = 0, y = 0, xMin = 0, xMax = 0, yMin = 0, yMax = 0;

	for (double theta = 0.0; theta < 2*PI; theta+= 2.0*PI/numSides)
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

	_boundingBox._width = xMax-xMin;
	_boundingBox._height = yMax-yMin;
}

stringstream Polygon::getPostScript()
{
	stringstream ps;

	// save point
	ps << "gsave newpath 0 0 moveto\n";

	// Setup starting point of shape -- relative
	ps << (int)(-_boundingBox._width/2) << " " << (int)(-_boundingBox._height / 2) << " rmoveto\n";
	
	// setup loop of drawing -- angles
	ps << "0 " << (int)(360/_numSides) << " 360 {\n";
	
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

	return ps;
}

