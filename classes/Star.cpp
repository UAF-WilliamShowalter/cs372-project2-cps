// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Star.cpp

#include "Star.h"

#include <cmath>

Star::Star(double sideLength):_sideLength(sideLength)
{
	setBoundingBox(calculateBoundingBox());
	setPostScript(getBoundingCenterPostScript());
	setPostScript(getDrawBoundingBoxPostScript());
	setPostScript(calculatePostScript());
}

BoundingBox Star::calculateBoundingBox()
{
	double x = 0, y = 0, xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	double theta = -144*PI/180; // the constant rotate angle for a star

	//for (double theta = 0.0; theta < 2*PI; theta += 2.0*PI/_numSides)
	for(int i = 0; i < 4; ++i)
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

	//180-144=36

	return BoundingBox(_sideLength,_sideLength*std::sin(36));
	// TODO: Drawing the bounding box gives slightly different results than this.
}

std::string Star::calculatePostScript()
{
	std::stringstream ps;

	ps << "% BEGIN STAR\n";

	// save point
	ps << "gsave\n";
	ps << "newpath\n";
	ps << "0 0 moveto\n";

	// TODO: remove magic numbers from this line
	ps << (int)(-getBoundingBox()._width/2) << " " << (int)((-getBoundingBox()._height/2)-_sideLength/2.6) << " rmoveto\n";
	
	ps << "currentpoint translate\n";
	ps << "4 {\n";
	ps << _sideLength << " 0 lineto\n";
	ps << "currentpoint translate\n"; // move origin
	ps << "-144 rotate\n";
	ps << "} repeat\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	ps << "% END STAR\n\n";

	return ps.str();
}

