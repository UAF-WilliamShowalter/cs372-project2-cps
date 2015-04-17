// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// CompoundShape.cpp

#include "CompoundShape.h"
#include <iostream>
#include <sstream>

BoundingBox CompoundShape::calculateBoundingBox() {

	return getCompoundBoundingBox(_shapes);
}

std::string CompoundShape::calculatePostScript() {
	std::stringstream ps;
	BoundingBox previous;

	ps<<"gsave\n";

	if(_shapes.size()>0)
	{
		std::string temp = _shapes[ii]->getPostScript();
		temp.erase(0, temp.find("\n") + 1);
		ps<<temp;
		//shift dimension/2

		for (size_t ii=1;ii<_shapes.size();++ii) 
		{
			//shift dimension/2
			std::string temp = _shapes[ii]->getPostScript();
			temp.erase(0, temp.find("\n") + 1);
			ps<<temp;
			//shift dimension/2
		}
	}

	ps<<"grestore\n";

	return ps.str();
}