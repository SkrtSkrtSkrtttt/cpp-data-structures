//Naafiul Hossain
//SBU ID: 115107623
#include "Point.h"
#include <cmath>

Point::Point() {
	xCord = 0;
	yCord = 0;
}

Point::Point(double x, double y) {
	xCord = x;
	yCord = y;
}

double Point::getX() {
	return xCord;
}

double Point::getY() {
	return yCord;
}

void Point::setX(double x) {
	xCord = x;
}

void Point::setY(double y) {
	yCord = y;
}

double Point::dist2origin() {
	return sqrt(xCord * xCord + yCord * yCord);
}

