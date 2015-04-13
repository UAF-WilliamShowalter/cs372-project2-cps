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

#include "classes/Shape.h" // Shape has includes from <memory> and <string>
#include "classes/CompoundShape.h"
#include "classes/Polygon.h"
#include "classes/Rectangle.h"
#include "classes/Circle.h"
#include "classes/ShapeDecorator.h"

TEST_CASE("Implement C++ to PostScript.", "CPS")
{
	Polygon polygon1(9, 72); // 9 sides, each side is 72 in length
	Circle circle1(72); // radius is 72
	Rectangle rectangle1(72, 144); // width 72, height 144

	stringstream polygonPostScript = polygon1.getPostScript();
	stringstream rectanglePostScript = rectangle1.getPostScript();
	stringstream circlePostScript = circle1.getPostScript();

	// console output test
	cout << "%!\n";
	cout << "288 288 translate\n";
	std::string temp;
	while (std::getline(circlePostScript,temp)){
		cout << temp << endl;
	}
	cout << "showpage\n";
    REQUIRE(0==0);
}
