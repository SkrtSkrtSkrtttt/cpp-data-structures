//Naafiul Hossain
//SBU ID: 115107623


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int factorial(int n) {  //recursion 
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int countTrailingZeros(int n) {
    int count = 0;
    int divisor = 5;

    while (n / divisor > 0) {
        count += n / divisor;
        divisor *= 5;
    }

    return count;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    inputFile.close();  // Close the input file before renaming

    if (n < 0) {
        cout << "The negative number in the input file is: " << n << endl;
        n = abs(n);

        ofstream newInputFile("input.txt");
        newInputFile << n;
        newInputFile.close();

        cout << "The negative number has been changed to its positive equivalent in input.txt." << endl;
    }

    int choice = 0;

    while (choice != 3) {
        cout << "Menu:\n";
        cout << "1. Calculate number of trailing zeros\n";
        cout << "2. Change the negative number to positive\n";
        cout << "3. Terminate\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            ifstream inputFile("input.txt");
            ofstream outputFile("output.txt");

            if (!inputFile.is_open()) {
                cout << "Unable to open input file." << endl;
                return 1;
            }

            int n;
            inputFile >> n;

            int trailingZeros = countTrailingZeros(n);

            outputFile << "Number of trailing zeros in " << n << "! is: " << trailingZeros;
            cout << "Result written to output.txt." << endl;

            inputFile.close();
            outputFile.close();
            break;
        }
        case 2:
            cout << "The negative number has been changed to its positive equivalent in input.txt." << endl;
            break;
        case 3:
            cout << "Terminating the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}



