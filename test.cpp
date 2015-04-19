// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// test.cpp

// main.cpp is the release suite
// test.cpp is the test/debug suite

#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <cstdio>
using std::remove;

#include "classes/Shape.h"
#include "classes/CompoundShape.h"
#include "classes/Polygon.h"
#include "classes/Rectangle.h"
#include "classes/Circle.h"
#include "classes/ShapeDecorator.h"
#include "classes/ScaledShape.h"
#include "classes/RotatedShape.h"
#include "classes/Triangle.h"
#include "classes/Square.h"
#include "classes/Spacer.h"
#include "classes/Star.h"

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

TEST_CASE("Implement C++ to PostScript.", "CPS")
{
	//Shape::flipDrawBoundingBox(); // turns on drawing of bounding boxes

	Polygon polygon1(9, 72); // 9 sides, each side is 72 in length
	Triangle triangle1(72);
	Square square1(72);
	Spacer spacer1(72,72);
	Star star1(72);

	RotatedShape rotatedpolygon1(make_shared<Polygon>(polygon1), Ninety);
	ScaledShape scaledpolygon1(make_shared<Polygon>(polygon1), 2, 2);
	RotatedShape rotatedscaledpolygon1(make_shared<ScaledShape>(scaledpolygon1), Ninety);
	ScaledShape scaledrotatedscaledpolygon1(make_shared<RotatedShape>(rotatedscaledpolygon1), 0.1, 0.1);

	//Circle circle1(72); // radius is 72
	//Rectangle rectangle1(72, 144); // width 72, height 144

	string fileName = "experiment.ps";
	if(ifstream(fileName)) // if the file exists
	{
		remove("experiment.ps"); // delete it
	}

	writePostScriptToFile(&polygon1, fileName);
	writePostScriptToFile(&triangle1, fileName);
	writePostScriptToFile(&square1, fileName);
	writePostScriptToFile(&spacer1, fileName);
	writePostScriptToFile(&star1, fileName);

	writePostScriptToFile(&rotatedpolygon1, fileName);
	writePostScriptToFile(&scaledpolygon1, fileName);
	writePostScriptToFile(&rotatedscaledpolygon1, fileName);
	writePostScriptToFile(&scaledrotatedscaledpolygon1, fileName);

	//writePostScriptToFile(&circle1, fileName);
	//writePostScriptToFile(&rectangle1, fileName);

	/*Shape *polygon;

	for(int i=0; i<100; ++i)
	{
		polygon = new Polygon(i, 72);
		writePostScriptToFile(polygon, fileName);
		delete polygon;
	}*/

	REQUIRE(0==0);
}
