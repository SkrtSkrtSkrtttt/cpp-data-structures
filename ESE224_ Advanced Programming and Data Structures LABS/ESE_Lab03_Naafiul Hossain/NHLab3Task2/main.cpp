//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("data_1.dat");
	ofstream fout("data1report.dat");
	int num=0;
	double width = 0;
	double height = 0;
	double totalArea = 0;
	double totalSquareArea = 0;
	int sqaureCount = 0;
	double minArea = 100;
	double maxArea = width * height;
	if (fin.fail()) {
		cerr << "error opening input file" << endl;
		exit(1);

	}
	if (fout.fail()) {
		cerr << "erorr opening output file" << endl;
		exit(1);
	}
	cout << "reading and writting" << endl;
	fin >> num;
	//fout << num;

	for (int i = 0; i < num; i++) {
		fin >> width;
		fin >> height;
		double area = width * height;
		totalArea += area;
		if (width == height) {
			totalSquareArea += area;
			sqaureCount++;
		}
		if (area > maxArea) {
			maxArea = area;
		}
		if (area < minArea) {
			minArea = area;
			//cout << " minarea each iteration : " << minArea << endl;
		}

	}
	double averageArea = totalArea / num;
	double averageSquareArea;

	if (sqaureCount > 0) {
		averageSquareArea = totalSquareArea / sqaureCount;
	}
	else {
		averageSquareArea = 0;
	}


	fout << "Maximum area: " << maxArea << endl;
	fout << "Minimum area: " << minArea << endl;
	fout << "Average area of all rectangles: " << averageArea << endl;
	fout << "Average area of all squares: " << averageSquareArea << endl;
	fin.close();
	fout.close();
	cout << "Data written to data1report.dat" << endl;
	return 0;


}