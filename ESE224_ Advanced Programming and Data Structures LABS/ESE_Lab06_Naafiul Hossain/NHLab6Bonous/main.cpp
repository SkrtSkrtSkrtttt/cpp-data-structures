//Naafiul Hossain

//backtracking


#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == digit || board[i][col] == digit || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char digit = '1'; digit <= '9'; digit++) {
                    if (isValid(board, row, col, digit)) {
                        board[row][col] = digit;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = '.'; // Backtrack if the solution is not valid
                    }
                }
                return false; // No valid digit found, need to backtrack
            }
        }
    }
    return true; // All cells filled, puzzle is solved
}

void printSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Original Sudoku Puzzle:" << endl;
    printSudoku(sudoku);

    if (solveSudoku(sudoku)) {
        cout << "\nSolved Sudoku Puzzle:" << endl;
        printSudoku(sudoku);
    }
    else {
        cout << "\nNo solution found." << endl;
    }

    return 0;
}
