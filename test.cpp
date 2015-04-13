// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// test.cpp

// main.cpp is the release suite
// test.cpp is the test/debug suite

#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"

#include <string>
using std::string;

#include <sstream>
using std::ofstream;

#include "classes/Shape.h" // Shape has includes from <memory> and <string>
#include "classes/CompoundShape.h"
#include "classes/Polygon.h"
#include "classes/Rectangle.h"
#include "classes/Circle.h"
#include "classes/ShapeDecorator.h"

/*
void writePostScriptToFile(Shape *shape, string fileName)
{
	// file output test: polygon
	stringstream shapePostScript = shape.getPostScript();

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << "%!\n";
	outputFile << "288 288 translate\n";
	string temp;
	while (std::getline(polygonPostScript,temp))
	{
		outputFile << temp << "\n";
	}
	outputFile << "showpage\n";
	outputFile.close();
}
*/

TEST_CASE("Implement C++ to PostScript.", "CPS")
{
	Polygon polygon1(9, 72); // 9 sides, each side is 72 in length
	Circle circle1(72); // radius is 72
	Rectangle rectangle1(72, 144); // width 72, height 144

	stringstream polygonPostScript = polygon1.getPostScript();
	stringstream rectanglePostScript = rectangle1.getPostScript();
	stringstream circlePostScript = circle1.getPostScript();

	// file output test: polygon
	ofstream outputFile;
	outputFile.open("experiment.ps");
	outputFile << "%!\n";
	outputFile << "288 288 translate\n";
	string temp;
	while (std::getline(polygonPostScript,temp))
	{
		outputFile << temp << "\n";
	}
	outputFile << "showpage\n";
	outputFile.close();

	// file output test: circle
	outputFile.open("experiment.ps", std::ios_base::app);
	outputFile << "%!\n";
	outputFile << "288 288 translate\n";
	while (std::getline(circlePostScript,temp))
	{
		outputFile << temp << "\n";
	}
	outputFile << "showpage\n";
	outputFile.close();

	// file output test: rectangle
	outputFile.open("experiment.ps", std::ios_base::app);
	outputFile << "%!\n";
	outputFile << "288 288 translate\n";
	while (std::getline(rectanglePostScript,temp))
	{
		outputFile << temp << "\n";
	}
	outputFile << "showpage\n";
	outputFile.close();

    REQUIRE(0==0);
}
