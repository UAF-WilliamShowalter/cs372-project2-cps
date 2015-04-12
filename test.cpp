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
	Circle c;
	Rectangle r;
	Polygon p(5,72);
	stringstream ps = p.getPostScript();

	// Console output test
	cout << "144 144 translate\n";
	std::string temp;
	while (std::getline(ps,temp)){
		cout << temp << endl;
	}
	cout << "showpage\n";
    REQUIRE(0==0);
}
