//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <random>

using namespace std; 

int main() {
    int N;

    // Ask the user to input the value of N
    cout << "Enter the number of random double numbers to generate (N): ";
    cin >> N;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(1.0, 2.0);

    double sum = 0.0;
    double maximum = numeric_limits<double>::min();
    double minimum = numeric_limits<double>::max();

    cout << "Random numbers: ";

    for (int i = 0; i < N; ++i) {
        double random_number = dis(gen);
        sum += random_number;

        // Update maximum and minimum
        if (random_number > maximum)
            maximum = random_number;
        if (random_number < minimum)
            minimum = random_number;

        cout << random_number << " ";
    }

    double average = sum / N;

    cout << "\n\nAverage: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}
