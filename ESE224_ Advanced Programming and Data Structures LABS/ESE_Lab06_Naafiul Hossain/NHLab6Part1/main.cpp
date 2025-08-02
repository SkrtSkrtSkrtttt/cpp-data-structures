//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int k = A[0].size();
    int n = B[0].size();

    if (k != B.size()) {
        cerr << "Matrix dimensions are not suitable for multiplication. Exiting." << endl;
        exit(1);
    }

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < k; x++) {
                result[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    return result;
}

// Function to perform matrix element-wise division
vector<vector<double>> elementWiseMatrixDivision(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();
    int p = B.size();
    int q = B[0].size();

    if (m != p || n != q) {
        cerr << "Matrix dimensions are not suitable for element-wise division. Exiting." << endl;
        exit(1);
    }

    vector<vector<double>> result(m, vector<double>(n, 0.0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = static_cast<double>(A[i][j]) / static_cast<double>(B[i][j]);
        }
    }

    return result;
}

int main() {
    int m, k, n;
    cout << "Enter the dimensions of matrix A (m x k): ";
    cin >> m >> k;

    vector<vector<int>> matrixA(m, vector<int>(k));

    cout << "Enter the values of matrix A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter the dimensions of matrix B (k x n): ";
    cin >> k >> n;

    vector<vector<int>> matrixB(k, vector<int>(n));

    cout << "Enter the values of matrix B:" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrixB[i][j];
        }
    }

    vector<vector<int>> productMatrix = multiplyMatrices(matrixA, matrixB);
    vector<vector<double>> divisionMatrix = elementWiseMatrixDivision(matrixA, matrixB);

    // Sort the productMatrix in ascending order
    for (int i = 0; i < m; i++) {
        sort(productMatrix[i].begin(), productMatrix[i].end());
    }

    // Sort the divisionMatrix in descending order
    for (int i = 0; i < m; i++) {
        sort(divisionMatrix[i].rbegin(), divisionMatrix[i].rend());
    }

    // Output the results
    cout << "Matrix C (A * B) sorted in ascending order:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << productMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix D (A / B) sorted in descending order:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << divisionMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

