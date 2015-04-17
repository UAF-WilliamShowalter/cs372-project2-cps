// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// test.cpp

// main.cpp is the release suite
// test.cpp is the test/debug suite

#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
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

TEST_CASE("Implement C++ to PostScript.", "CPS")
{
	Polygon polygon1(9, 72); // 9 sides, each side is 72 in length
	Polygon polygon2(13, 72); // 9 sides, each side is 72 in length
	Circle circle1(72); // radius is 72
	Rectangle rectangle1(72, 144); // width 72, height 144

	shared_ptr<Shape> layered1 = make_shared<Layered>(std::initializer_list<shared_ptr<Shape>>
				({make_shared<Circle>(72), make_shared<Polygon>(9,72)}));

	shared_ptr<Shape> vertical1 = make_shared<Vertical>(std::initializer_list<shared_ptr<Shape>>
				({make_shared<Circle>(72), make_shared<Polygon>(9,72)}));

	shared_ptr<Shape> horizontal1 = make_shared<Horizontal>(std::initializer_list<shared_ptr<Shape>>
				({make_shared<Circle>(72), make_shared<Polygon>(9,72)}));

	shared_ptr<Shape> horizontalVerticalStack = 
			make_shared<Horizontal>(std::initializer_list<shared_ptr<Shape>>
				({make_shared<Circle>(72),vertical1}));

	string fileName = "experiment.ps";

	if(ifstream(fileName)) // if the file exists
	{
		remove("experiment.ps"); // delete it
	}

//	writePostScriptToFile(layered1.get(), fileName);
	writePostScriptToFile(horizontalVerticalStack.get(), fileName);
//	writePostScriptToFile(horizontal1.get(), fileName);
//	writePostScriptToFile(&polygon1, fileName);
//	writePostScriptToFile(&polygon2, fileName);
//	writePostScriptToFile(&circle1, fileName);
//	writePostScriptToFile(&rectangle1, fileName);

	/*Shape *polygon;

	for(int i=0; i<100; ++i)
	{
		polygon = new Polygon(i, 72);
		writePostScriptToFile(polygon, fileName);
		delete polygon;
	}*/

	REQUIRE(0==0);
}
