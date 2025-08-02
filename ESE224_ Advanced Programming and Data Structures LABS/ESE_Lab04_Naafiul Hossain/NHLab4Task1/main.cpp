//Naafiul Hossain
// sbu id: 115107623
#include <iostream>
#include <fstream>

using namespace std;
void swap(double&, double&);
void fakeSwap(double, double);

int main() {
	double a, b;
	ifstream datain;
	datain.open("input.dat");
	if (datain.fail()) {
		cerr << "File canot open";
		exit(1);
	}
	ofstream dataout;
	dataout.open("output.dat");
	if (dataout.fail()) {
		cerr << "File canot open";
		exit(1);
	}
	while (!datain.eof()) {
		datain >> a >> b;
		fakeSwap(a, b);
		dataout << a << " "<< b << endl;
		swap(a, b);
		dataout << a << " " << b << endl;
	}
	datain.close();
	dataout.close();
	return 0;
}
void swap(double& a, double& b) {
	double temp;
	temp = a;
	a = b;
	b = temp;
}
void fakeSwap(double a, double b) {
	double temp = a;
	a = b;
	b = temp;
}