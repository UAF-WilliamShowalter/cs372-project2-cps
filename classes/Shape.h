// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#define PI 3.14159265358979323846

#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

struct Coordinate
{
	// TODO: Coordinates as floats/doubles?
	int x, y;
};

struct BoundingBox
{
	Coordinate coordinate; // Start in the middle of the bounding box.
	double width, height;
};

class Shape
{
private:
	// TODO: Might be a better way to do this than copy-paste in every derived class.
	// Protected? Friend? Dumb getters/setters that have no security?

	//BoundingBox _boundingBox;
	//Coordinate _currentCoordinate;
	//stringstream _postScriptCode;

public:
	virtual ~Shape() = default;
	virtual BoundingBox getBoundingBox() = 0;
	virtual Coordinate getCoordinate() = 0;
	virtual stringstream getPostScript() = 0;
};

#endif