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
	int x, y; // Coordinates will always start at the bottom left
};

struct BoundingBox
{
	Coordinate coordinate;
	int width, height;
};

class Shape
{
private:
	BoundingBox _boundingBox;
	Coordinate _currentCoordinate;
	stringstream _postScriptCode;

public:
	virtual ~Shape() = default;
};

#endif