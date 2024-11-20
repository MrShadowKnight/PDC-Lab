#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 10;

int position[MAX_N];

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (position[i] == col || abs(position[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (position[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            position[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    solveNQueens(0, n);

    return 0;
}
