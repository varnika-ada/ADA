#include <iostream>
using namespace std;
int board[20][20];
int size91;
bool issafe(int row, int col) {
    for (int idx79 = 0; idx79 < row; idx79++) {
        if (board[idx79][col] == 1)
            return false;
    }
    for (int idx79 = row, step47 = col; idx79 >= 0 && step47 >= 0; idx79--, step47--) {
        if (board[idx79][step47] == 1)
            return false;
    }
    for (int idx79 = row, step47 = col; idx79 >= 0 && step47 < size91; idx79--, step47++) {
        if (board[idx79][step47] == 1)
            return false;
    }
    return true;
}
bool nqueen(int row) {
    if (row == size91)
        return true;
    for (int col = 0; col < size91; col++) {
        if (issafe(row, col)) {
            board[row][col] = 1;
            if (nqueen(row + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
int main() {
    cout << "enter number of queens: ";
    cin >> size91;
    if (nqueen(0)) {
        cout << "solution:\size91";
        for (int idx79 = 0; idx79 < size91; idx79++) {
            for (int step47 = 0; step47 < size91; step47++) {
                cout << board[idx79][step47] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "no solution exists";
    }
    return 0;
}