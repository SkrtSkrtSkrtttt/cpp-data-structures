//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using std::ofstream;
using std::ifstream;
using namespace std;

int main() {
    // Open the output files for writing
    ofstream foutCosine("cosine.txt");
    ofstream foutSine("sine.txt");

    if (!foutCosine.is_open() || !foutSine.is_open()) {
        cerr << "Error opening output file(s)." << endl;
        return 1;  // Exit the program with an error status
    }

    // Get the number of samples from the user (minimum: 50)
    int numSamples;
    std::cout << "Enter the number of samples (minimum 50): ";
    std::cin >> numSamples;

    // Calculate the angle intervals
    double interval = (2 * 3.14159265358979323846) / numSamples;

    // Iterate through the intervals and calculate cosine and sine
    for (int i = 0; i < numSamples; i++) {
        double angle = i * interval;
        double cosValue = cos(angle);
        double sinValue = sin(angle);

        // Write angle and cosine to cosine.txt
        foutCosine << std::fixed << std::setprecision(2) << angle << "\t" << cosValue << "\n";

        // Write angle and sine to sine.txt
        foutSine << std::fixed << std::setprecision(2) << angle << "\t" << sinValue << "\n";
    }

    // Close the output files
    foutCosine.close();
    foutSine.close();

    // Open the input files for reading
    ifstream finCosine("cosine.txt");
    ifstream finSine("sine.txt");

    if (!finCosine.is_open() || !finSine.is_open()) {
        cerr << "Error opening input file(s)." << endl;
        return 1;  // Exit the program with an error status
    }

    // Calculate RMSE
    double sumSquaredError = 0.0;
    double angle, actualValue, predictedValue;

    for (int i = 0; i < numSamples; i++) {
        finSine >> angle >> actualValue;  // Read angle and actual sine value
        finCosine >> angle >> predictedValue;  // Read angle and predicted cosine value

        double error = actualValue - predictedValue;
        sumSquaredError += error * error;
    }

    // Calculate RMSE
    double rmse = sqrt(sumSquaredError / numSamples);
    cout << "Root Mean Squared Error: " << rmse << endl;

    // Close the input files
    finCosine.close();
    finSine.close();

    return 0;
}


