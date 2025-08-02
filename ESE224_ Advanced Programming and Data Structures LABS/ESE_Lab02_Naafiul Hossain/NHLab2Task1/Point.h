#pragma once
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
	double Distance(const Point& p2) const;
	double operator -(const Point& p2) const;
	bool Equal(const Point& p2) const;
	bool operator==(const Point& p2)const;
	void Print();
	void operator*(double n);
	bool operator>(const Point& p2) const;


};
