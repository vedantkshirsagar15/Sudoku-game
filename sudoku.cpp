#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool safe(int row, int col, vector<vector<int>>& board, int val) {
        for (int i = 0; i < 9; i++) {
            // Row check
            if (board[row][i] == val) {
                return false;
            }
            // Column check
            if (board[i][col] == val) {
                return false;
            }
            // 3x3 matrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Empty cell
                if (board[row][col] == 0) {
                    for (int val = 1; val <= 9; val++) {
                        if (safe(row, col, board, val)) {
                            board[row][col] = val;
                            // Recursion
                            if (solve(board)) {
                                return true;
                            } else {
                                // Backtracking
                                board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> grid(9, vector<int>(9, 0));
        // Convert char board to int grid
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    grid[i][j] = board[i][j] - '0';
                }
            }
        }
        // Solve the Sudoku
        if (solve(grid)) {
            // Convert int grid back to char board
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    board[i][j] = grid[i][j] + '0';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the Sudoku puzzle (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution sudokuSolver;

    vector<vector<int>> grid(9, vector<int>(9, 0));
    // Convert char board to int grid
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                grid[i][j] = board[i][j] - '0';
            }
        }
    }

    // Solve the Sudoku
    if (sudokuSolver.solve(grid)) {
        // Convert int grid back to char board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = grid[i][j] + '0';
            }
        }

        // Print the solved Sudoku board
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found!\n";
    }

    return 0;
}