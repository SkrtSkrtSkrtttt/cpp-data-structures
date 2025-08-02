//Naafiul Hossain
//SBU ID: 115107623
#pragma once
class Point {
private:
	double xCord, yCord;
public:
	Point();
	Point(double x, double y);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	double dist2origin();
};