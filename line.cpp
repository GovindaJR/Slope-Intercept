/*
file: line.h
by: Govinda Ramrattan
org: COP 2001, 202101, 10409
desc: implementation of a line class object
-----------------------------------------------------------*/

#define _USE_MATH_DEFINES 
#include<math.h>
#include"line.h"

// constructors
//---------------------------------------------------------
/**
default constructor - initalize empty line
*/

Line::Line() 
{
	point1 = Point{0,0};
	point2 = Point{ 0,0 };
	slope = 0;
}

/**
properties constructor - initalize to parameter values
*/
Line::Line(Point point1, Point point2)
{
	this->point1 = point1;
	this->point2 = point2;

}

Line::Line(Point point1, float slope)
{
	this->point1 = point1;
	this->slope = slope;
}


// accessors
// ---------------------------------------------------------
// getters

Point Line::getPoint1() { return point1; }
Point Line::getPoint2() { return point2; }
float Line::getSlope() { return slope; }

// setters

void Line::setPoint1(Point value) { point1 = value; }
void Line::setPoint2(Point value) { point2 = value; }
void Line::setSlope(float value) { slope = value; }

// member methods

/**
Calculates the difference in x values of the two points of the line.

Returns:
xDifference		the difference in x values.
*/
float Line::calcDiffX()
{
	float xDifference = point2.getXCoordinate() - point1.getXCoordinate();

	return xDifference;
}


/**
Calculates the difference in y values of the two points of the line.

Returns:
yDifference		the difference in y values.
*/
float Line::calcDiffY()
{
	float yDifference = point2.getYCoordinate() - point1.getYCoordinate();

	return yDifference;
}


/**
	Calculates the slope of the line depending on the mode.
*/
void Line::calcSlope(Mode mode)
{
	if (mode == TWO_POINT)
	{
		slope = ((calcDiffY()) / (calcDiffX()));
	}
	else if (mode == POINT_SLOPE)
	{
		setPoint2({ 0, calcYIntercept() });
	}


}

/**
finds the y-intercept using a point and the slope

Returns:
yIntercept	value used to plot the function
*/
float Line::calcYIntercept()
{
	float yIntercept = point1.getYCoordinate() - (slope * point1.getXCoordinate());
	return yIntercept;
}


/**
finds the distance between two points on a line

Returns:
length		the distance between two points
*/
float Line::lineLength()
{
	float length = sqrt(pow(calcDiffX(), 2) +
		pow(calcDiffY(), 2));


	return length;
}


/**
finds the angle between the line and the top of the y - axis or zero degrees

Returns:
cardinal	refers to angle used to graph the line
*/
float Line::lineAngle()
{
	float radians = atan2((calcDiffY()), (calcDiffX()));
	float angle = radians * 180.0 / M_PI;
	float degrees = 90.0 - angle;
	float cardinal = (degrees > 0.0 ? degrees : degrees + 360.0);

	return cardinal;
}
