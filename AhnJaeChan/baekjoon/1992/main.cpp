#include <iostream>
#include <string>

using namespace std;

bool board[64][64];

string check_part(int row, int col, int n) {
    bool pixel = board[row][col];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[row + i][col + j] != pixel) {
                return "(";
            }
        }
    }

    return pixel ? "1" : "0";
}

string compress(int row, int col, int n) {
    if (n == 1) {
        return board[row][col] ? "1" : "0";
    }

    string result = check_part(row, col, n);

    if (result != "(") {
        return result;
    }

    int step = n / 2;

    string upper_left = compress(row, col, step);
    string upper_right = compress(row, col + step, step);
    string lower_left = compress(row + step, col, step);
    string lower_right = compress(row + step, col + step, step);

    return "(" + upper_left + upper_right + lower_left + lower_right + ")";
}

int main() {
    string line;
    int N;

    cin >> N;

    for (int row = 0; row < N; row++) {
        int col = 0;
        cin >> line;

        for (char element: line) {
            board[row][col++] = element == '1';
        }
    }

    line = compress(0, 0, N);
    cout << line<< endl;

    return 0;
}