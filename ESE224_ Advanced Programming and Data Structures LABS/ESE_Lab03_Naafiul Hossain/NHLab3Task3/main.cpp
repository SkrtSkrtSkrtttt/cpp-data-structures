//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to calculate Fibonacci number for a given input n
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ifstream fin("data3.dat");
    ofstream fout("data3fib.dat");
    int fib = 0;

    if (fin.fail()) {
        cerr << "Error opening input file" << endl;
        exit(1);
    }

    if (fout.fail()) {
        cerr << "Error opening output file" << endl;
        exit(1);
    }

    cout << "Reading and writing" << endl;

    // Read each value from the input file
    while (fin >> fib) {
        // Calculate the Fibonacci number for the current value
        int fibonacci_num = fibonacci(fib);

        // Write the result to the output file
        fout << "Fibonacci of " << fib << " is " << fibonacci_num << "\n";
    }

    // Close the input and output files
    fin.close();
    fout.close();

    return 0;
}
