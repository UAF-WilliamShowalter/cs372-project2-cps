// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Circle.h

#include "Circle.h"

stringstream Circle::getPostScript()
{
	stringstream ps;
	
	// save point
	ps << "0 0 moveto gsave newpath\n";
	
	// draw circle
	ps << "0 0 " << (int)(_boundingBox._width) << " 0 360 arc\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	return ps;
}