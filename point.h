/*
file: point.h
by: Govinda Ramrattan
org: COP 2001, 202101, 10409
desc: declaration of a point class object
-----------------------------------------------------------*/

#ifndef POINT_H
#define POINT_H

class Point {
public:
	// constructors
	Point();
	Point(float xCoordinate, float yCoordinate);

	// accessors
	// getters
	float getXCoordinate();
	float getYCoordinate();

	// setters
	void setXCoordinate(float value);
	void setYCoordinate(float value);

private:
	float xCoordinate;
	float yCoordinate;

};



#endif // POINT_H