// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// main.cpp

// main.cpp is the release suite
// test.cpp is the test/debug suite

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
#include <fstream>
using std::stringstream;
using std::ifstream;
using std::ofstream;

#include <cstdio>
using std::remove;

#include <memory>
using std::make_shared;
using std::make_unique;
using std::shared_ptr;

#include "classes/Shape.h"
#include "classes/CompoundShape.h"
#include "classes/Polygon.h"
#include "classes/Rectangle.h"
#include "classes/Circle.h"
#include "classes/ShapeDecorator.h"
#include "classes/Layered.h"
#include "classes/Horizontal.h"
#include "classes/Vertical.h"


void writePostScriptToFile(Shape *shape, string fileName)
{
	stringstream shapePostScript(shape->getPostScript());

	ofstream outputFile(fileName, std::ios_base::app);
	string temp;
	while (std::getline(shapePostScript,temp))
	{
		outputFile << temp << "\n";
	}
	outputFile << "showpage\n\n";
	outputFile.close();
}

int main(int argc, char*argv[])
{
	Shape::flipDrawBoundingBox(); // turns on drawing of bounding boxes

	return 0;
}
