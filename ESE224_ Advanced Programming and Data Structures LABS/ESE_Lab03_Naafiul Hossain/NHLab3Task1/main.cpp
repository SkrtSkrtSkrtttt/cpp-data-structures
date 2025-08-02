//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream fin("input.dat");
	ofstream fout("outpu.dat");
	string content;
	if (fin.fail()) {
		cerr << "error trying to open the input file" << endl;
		exit(1);
	}
	if (fout.fail()) {
		cerr << "error trying to open the output file" << endl;
	}
	cout << "reading and wrtting" << endl;
	fin >> content;
	fout << content;
	fin.close();
	fout.close();
	system("pause");
	return 0;
}