//Naafiul Hossain
//SBU ID: 115107623
#include "Point.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

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
double Point::Distance(const Point& p2) const {
	double dx = p2.xCord - xCord;
	double dy = p2.yCord - yCord;
	return sqrt(pow(dx, 2) + pow(dy, 2));

}
double Point::operator-(const Point& p2) const {
	double dx = p2.xCord - xCord;
	double dy = p2.yCord - yCord;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}
bool Point::Equal(const Point& p2) const {
	return (p2.xCord == xCord) && (p2.yCord == yCord);

}
bool Point::operator==(const Point& p2) const {
	return (p2.xCord == xCord) && (p2.yCord == yCord);
}
void Point::Print() {
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << "The Point is (" << xCord << "," << yCord << ")" << endl;
}
void Point::operator*(double n) {
	xCord = xCord * n;
	yCord = yCord * n;
}
bool Point::operator>(const Point& p2)const {
	double d1 = sqrt(pow(xCord, 2) + pow(yCord, 2));
	double d2= sqrt(pow(p2.xCord, 2) + pow(p2.yCord, 2));
	return d1 > d2;
}