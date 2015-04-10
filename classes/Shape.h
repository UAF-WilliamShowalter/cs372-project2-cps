// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using std::string;
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

public:
	virtual ~Shape() = default;
};

#endif