// CS 372 Project 2
// CPS: C++ to PostScript
// Noah Betzen, William Showalter, Saira Walia
// ShapeDecorator.cpp

#include "ShapeDecorator.h"


ShapeDecorator::ShapeDecorator(std::shared_ptr<Shape> decoratedShape):_theShape(decoratedShape)
{

}

/*
BoundingBox ShapeDecorator::DecalculateBoundingBox()
{

}

std::string ShapeDecorator::calculatePostScript()
{

}
*/

std::shared_ptr<Shape> ShapeDecorator::getTheShape()
{
	return _theShape;
}

/*
void ShapeDecorator::setTheShape(std::shared_ptr<Shape> shape)
{
	_theShape = shape;
}
*/