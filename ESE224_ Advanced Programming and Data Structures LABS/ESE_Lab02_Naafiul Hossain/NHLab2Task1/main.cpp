//Naafiul Hossain
//SBU ID: 115107623
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{

	/*cout << "Creating a point with the default constructor: " << endl;
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
	
	Point p1(2, 3);
	Point p2(3, 4);

	p1.Equal(p2);
	p1 == p2;
	*/
	double x, y, r;
	cout << "Enter the cords of p1:" << endl;
	cin >> x >> y;
	Point p1(x, y);
	p1.Print();
	cout << "Enter the cords of p2:" << endl;
	cin >> x >> y;
	Point p2(x, y);
	p2.Print();
	cout << "The distance between two points is" << p1.Distance(p2) << endl;
	cout << "The distance between two points is" << p1-p2 << endl;
	cout << "Are the two points the same? The answer is " << p2.Equal(p1) << endl;
	cout << "Are the two points the same The answer is" << (p1==p2) << endl<<endl;
	cout << "Enter a number to change the coords of p2: " << endl;
	cin >> r;
	p2* r;
	p2.Print();
	cout << "p1 > p2 ?" << (p1 > p2) << endl;
	system("pause");
	return 0;
}