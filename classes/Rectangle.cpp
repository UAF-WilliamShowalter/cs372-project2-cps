// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Rectangle.cpp

#include "Rectangle.h"

stringstream Rectangle::getPostScript()
{
	stringstream ps;
	
	// save point
	ps << "gsave newpath 0 0 moveto\n";
	
	// setup starting point of shape (relative)
	ps << (int)(-_boundingBox._width/2) << " " << (int)(-_boundingBox._height/2) << " rmoveto\n";
	
	// draw rectangle
	ps << "0 " << (int)(_boundingBox._width) << " rlineto\n";
	ps << (int)(_boundingBox._height) << " 0 rlineto\n";
	ps << "0 " << (int)(-_boundingBox._width) << " rlineto\n";
	ps << (int)(-_boundingBox._height) << " 0 rlineto\n";
	ps << "closepath\n";
	ps << "stroke\n";

	// restore point
	ps << "grestore\n";

	return ps;
}