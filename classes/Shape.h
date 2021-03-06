// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#define PI 3.14159265358979323846

#include <iostream>
#include <string> // for `string`
#include <sstream> // for `stringstream`
#include <memory> // for `unique_ptr`, `make_unique`, `move`

struct Coordinate
{
	Coordinate():_x(0),_y(0){}
	Coordinate(int x, int y):_x(x),_y(y){}
	
	int _x, _y;
};

// middle of an 8.5 inch by 11 inch paper
const Coordinate MIDDLEOFPAGE((int)(8.5*0.5*72),(int)(11*0.5*72));

struct BoundingBox
{
	BoundingBox():_center(MIDDLEOFPAGE),_width(0),_height(0){}

	BoundingBox(double width, double height):_center(MIDDLEOFPAGE),
											 _width(width),
											 _height(height){}
	BoundingBox(double width, double height, Coordinate center):_center(center),
																_width(width),
																_height(height){}

	Coordinate _center; // this is where shapes start its drawing
	double _width, _height;
};

class Shape
{
public:
	//Shape();
	virtual ~Shape() = default;
	static bool _drawBoundingBox; // starts false
	static void flipDrawBoundingBox();

	BoundingBox getBoundingBox();
	std::string getPostScript();

	void setBoundingBox(BoundingBox boundingBox);
	void setPostScript(std::string postScriptCode);
	void replacePostScript(std::string postScriptCode);

	// these are used by derived classes
	virtual BoundingBox calculateBoundingBox() = 0;
	virtual std::string calculatePostScript() = 0;

	virtual std::string getBoundingCenterPostScript();
	std::string getDrawBoundingBoxPostScript();
	void setCenter(Coordinate newCenter);

private:
	BoundingBox _boundingBox;
	std::string _postScriptCode;
};

#endif