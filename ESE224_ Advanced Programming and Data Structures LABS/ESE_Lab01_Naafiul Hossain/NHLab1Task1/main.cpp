//Naafiul Hossain
//SBU ID: 115107623
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Creating a point with the default constructor: " << endl;
	Point p1;
	cout << "The point is (" << p1.getX() << ", " << p1.getY() << ")" << endl;

	cout << "Creating a point with the parameterized constructor: " << endl;
	cout << "Enter two coordinates (x, y): ";
	double x, y;
	cin >> x >> y;
	Point p2(x, y);
	cout << "The point is (" << p2.getX() << ", " << p2.getY() << ")" << endl;

	cout << "Change the x coordinate of p2, enter the new coordinate: ";
	cin >> x;
	p2.setX(x);
	cout << "The point is (" << p2.getX() << ", " << p2.getY() << ")" << endl;

	cout << "Change the y coordinate of p2, enter the new coordinate: ";
	cin >> y;
	p2.setY(y);
	cout << "The point is (" << p2.getX() << ", " << p2.getY() << ")" << endl;

	cout << "Compute the point's euclidean distance to origin (0, 0): " << endl;
	double dist = p2.dist2origin();
	cout << "Distance to origin is: " << dist << endl;

	cout << "Press Enter to exit...";
	cin.ignore();
	cin.get();

	return 0;
}
