/*
file: point.h
by: Govinda Ramrattan
org: COP 2001, 202101, 10409
desc: implementation of a point class object
-----------------------------------------------------------*/

#include"point.h"

// constructors
//---------------------------------------------------------


/**
default constructor	- initalize empty point
*/
Point::Point()
{
	xCoordinate = 0;
	yCoordinate = 0;
}

/**
properties constructor - initalize to parameter values
*/

Point::Point(float xCoordinate, float yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
}


// accessors
// ---------------------------------------------------------
// getters
float Point::getXCoordinate() { return xCoordinate; }
float Point::getYCoordinate() { return yCoordinate; }

// setters
void Point::setXCoordinate(float value) { xCoordinate = value; }
void Point::setYCoordinate(float value) { yCoordinate = value; }

