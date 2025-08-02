//Naafiul Hossain
//SBU ID: 115107623
#include "line.h"
#include <iostream>

using namespace std;

int main() {
    double k, b, ck, cb;

    cout << "Enter the parameters for l1: " << endl;
    cin >> k >> b;
    Line l1(k, b);
    l1.print();

    cout << "Enter the parameters for line2: " << endl;
    cin >> k >> b;
    Line line2(k, b);
    line2.print();

    cout << "Enter a number to change the slope of line2: " << endl;
    cin >> ck;
    line2 = line2 * ck;
    line2.print();

    cout << "Enter a number to increment the intercept of line2: " << endl;
    cin >> cb;
    line2 = line2 + cb;
    line2.print();

    cout << "l1 == line2? " << (line2 == l1) << endl;

    system("pause");
    return 0;
}
