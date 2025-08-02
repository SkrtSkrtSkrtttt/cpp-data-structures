//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int totalPoints = 1000000; // Total number of random points to generate
    int pointsInsideCircle = 0; // Counter for points inside the circle

    double circleRadius = 1.0;

    for (int i = 0; i < totalPoints; i++) {
        // Generate random coordinates within the square [-1, 1] x [-1, 1]
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;

        // Check if the point is inside the circle
        if (x * x + y * y <= circleRadius * circleRadius) {
            pointsInsideCircle++;
        }
    }

    // Calculate the area of the circle using the ratio of points inside the circle to total points
    double estimatedArea = 4.0 * pointsInsideCircle / totalPoints;

    cout << "Estimated area of the circle: " << estimatedArea << endl;

    return 0;
}