//Naafiul Hossain
//SBU ID: 115107623 

#include <iostream>
#include <vector>
using namespace std;

// Returns a spiral matrix in clockwise order
vector<int> generateSpiralMatrix(vector<vector<int>>& matrix) {
    // Declare variables
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    // Vector to store the spiral matrix 
    vector<int> spiralResult;

    // Direction 
    // '0' = Left to Right 
    // '1' = Top to Bottom 
    // '2' = Right to Left 
    // '3' = Bottom to Top
    int direction = 0;

    while (top <= bottom && left <= right) {
        // Traverse left to right
        if (direction == 0) {
            for (int i = left; i <= right; i++)
                spiralResult.push_back(matrix[top][i]);

            top++;
            direction = 1;
        }
        // Traverse top to bottom 
        else if (direction == 1) {
            for (int i = top; i <= bottom; i++)
                spiralResult.push_back(matrix[i][right]);

            right--;
            direction = 2;
        }
        // Traverse right to left 
        else if (direction == 2) {
            for (int i = right; i >= left; i--)
                spiralResult.push_back(matrix[bottom][i]);

            bottom--;
            direction = 3;
        }
        // Traverse bottom to top 
        else if (direction == 3) {
            for (int i = bottom; i >= top; i--)
                spiralResult.push_back(matrix[i][left]);

            left++;
            direction = 0;
        }
    }

    return spiralResult;
}

int main() {
    // User input for 'm' and 'n'
    int rows, columns;
    //cin >> rows >> columns;
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> columns;
    // 2-D Vector 
    vector<vector<int>> inputMatrix;

    // Populate the 2-D vector
    int count = 1;
    for (int i = 0; i < rows; i++) {
        vector<int> tempRow;
        for (int j = 0; j < columns; j++)
            tempRow.push_back(count++);

        inputMatrix.push_back(tempRow);
    }

    // Store the Spiral Matrix result in 'result'
    vector<int> result = generateSpiralMatrix(inputMatrix);

    // Print the spiral matrix
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
