/*
file: line.h
by: Govinda Ramrattan
org: COP 2001, 202101, 10409
desc: declaration of a line class object
-----------------------------------------------------------*/

#ifndef LINE_H
#define LINE_H


#include"point.h"

class Line {
public:

	enum Mode {
		TWO_POINT,
		POINT_SLOPE,
		EXIT
	};

	// constructors
	Line();
	Line(Point point1, Point point2);
	Line(Point point1, float slope);

	// accessors
	// getters
	Point getPoint1();
	Point getPoint2();
	float getSlope();

	// setters
	void setPoint1(Point value);
	void setPoint2(Point value);
	void setSlope(float value);

	// member methods
	float calcDiffX();
	float calcDiffY();
	void calcSlope(Mode mode);
	float calcYIntercept();
	float lineLength();
	float lineAngle();


private:
	Point point1;
	Point point2;
	float slope;

};



#endif LINE_H