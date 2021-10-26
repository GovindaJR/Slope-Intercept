
/*
file: slopeintercept.cpp
by: Govinda Ramrattan
org: COP 2001, 202101, 10409
desc: slope intercept graph application
-----------------------------------------------------------*/
#include<iostream>
#define _USE_MATH_DEFINES 
#include<math.h>
#include <iomanip> 


#include "fgcugl.h"
#include"slopeintercept.h"
#include"line.h"
#include"point.h"



// function prototypes
Line::Mode getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);
void displayLine(Line line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);

int main()
{

	Line line;
	Line::Mode mode;

	
	mode = getProblem();

	while (mode != Line::EXIT)
	{
		// gets required points for the line depending on mode. 
		if (mode == Line::TWO_POINT)
		{
			get2Point(line);

		}
		else if (mode == Line::POINT_SLOPE)
		{
			getPointSlope(line);
		}

		line.calcSlope(mode);
		//calcLine(line, mode);

		std::cout << "\n";

		displayLine(line);

		std::cout << "\n";

		display2Pt(line);

		std::cout << "\n";

		displayPointSlope(line);

		std::cout << "\n\n";

		displaySlopeIntercept(line);

		std::cout << "\n\n";

		drawLine(line);

		mode = getProblem();
	}

	// displayed if user exits
	std::cout << "Program exited.";

	return 0;
}

/**
displays problem prompt to user and recieves input

Parameters:

Returns:
mode		user menu choice
*/
Line::Mode getProblem()
{
	std::cout << "Select the form that you would like to convert to slope intercept form:" << std::endl;
	std::cout << "	1) Two point form (you know two points of the line)" << std::endl;
	std::cout << "	2) Point slope form (you know the line's slope and one point" << std::endl;
	std::cout << "	3) exit \n -> ";

	int input;

	std::cin >> input;

	Line::Mode mode;

	switch (input)
	{
	case 1:
		mode = Line::TWO_POINT;
		break;
	case 2:
		mode = Line::POINT_SLOPE;
		break;
	case 3:
		mode = Line::EXIT;
	}

	return mode;
}

/**
prompts the user for an x and y coord and returns as a point.

Parameters:

Returns:
point		x and y coordinate
*/
Point getPoint()
{
	std::cout << "Please enter an X and Y coordinate (separated by space): ";

	float xCoordinate, yCoordinate;
	std::cin >> xCoordinate >> yCoordinate;

	Point point = { xCoordinate, yCoordinate };

	return point;
}


/**
gets two points to use for the line from the user

Parameters:
line		line of the function

Returns:
void
*/
void get2Point(Line& line)
{
	std::cout << "Enter the first point \n\n";
	line.setPoint1(getPoint());

	std::cout << "\n";

	std::cout << "Enter the second point \n\n";
	line.setPoint2(getPoint());
}


/**
gets a point and a slope value from the user

Parameters:
line		line used for the function

Returns:
void
*/
void getPointSlope(Line& line)
{
	line.setPoint1(getPoint());

	float slope;
	std::cout << "Please enter a slope value: ";
	std::cin >> slope;

	line.setSlope(slope);

}




/**
displays properties of the line on the console

Parameters:
line		line used for function

Returns:
void
*/
void displayLine(Line line)
{
	std::cout << "Line: \n" << std::endl;

	std::cout << "Point1 (" << line.getPoint1().getXCoordinate() << ", " << line.getPoint1().getYCoordinate() << ")" << std::endl;
	std::cout << "Point2 (" << line.getPoint2().getXCoordinate() << ", " << line.getPoint2().getYCoordinate() << ")" << std::endl;
	std::cout << "Slope = " << std::setprecision(3) << line.getSlope() << std::endl;
	std::cout << "Y Intercept = " << line.calcYIntercept() << std::endl;
	std::cout << "Length = " << std::setprecision(3) << line.lineLength() << std::endl;
	std::cout << "Angle = " << line.lineAngle() << std::endl;
}

/**

displays the two point form of the line on the console

Parameters:
line		line used for function

Returns:
void
*/
void display2Pt(Line line)
{
	std::cout << "Two Point Form: \n" << std::endl;
	std::cout << "	(" << line.getPoint2().getYCoordinate()<< " - " << line.getPoint1().getYCoordinate() << ")" << std::endl;
	std::cout << "m = -------------------" << std::endl;
	std::cout << "	(" << line.getPoint2().getXCoordinate() << " - " << line.getPoint1().getXCoordinate() << ")" << std::endl;

}


/**
displays point slope form of the line on the console

Parameters:
line		line used for function

Returns:
void
*/
void displayPointSlope(Line line)
{
	std::cout << "Point Slope Form: \n" << std::endl;
	std::cout << "y - " << line.getPoint1().getYCoordinate() << " = " << line.getSlope() << "(x - " << line.getPoint1().getXCoordinate() << ")";
}


/**
displays slope intercept form of the line on the console

Parameters:
line		line used for function

Returns:
void
*/
void displaySlopeIntercept(Line line)
{
	std::cout << "Slope Intercept Form: \n" << std::endl;
	std::cout << "y = " << line.getSlope() << "x + " << line.calcYIntercept();

}

/**
draws the line in an OpenGL window

Parameters:
line		line used for function

Returns:
void
*/
void drawLine(Line line)
{
	fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, false);

	while (!fgcugl::windowClosing())
	{
		// x axis
		fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2);
		// y axis
		fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
		// function
		fgcugl::drawLine(line.getPoint1().getXCoordinate() + WINDOW_WIDTH / 2, line.getPoint1().getYCoordinate() + WINDOW_HEIGHT / 2,
			line.getPoint2().getXCoordinate() + WINDOW_WIDTH / 2, line.getPoint2().getYCoordinate() + WINDOW_HEIGHT / 2, 1, fgcugl::Cyan);

		fgcugl::windowPaint();
		fgcugl::getEvents();
	}
	fgcugl::cleanup();
}