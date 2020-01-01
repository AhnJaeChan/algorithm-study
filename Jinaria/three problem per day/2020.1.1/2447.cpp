#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void func(vector<vector<char>> &board, int n, int size, int col, int row) {
    if (size == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[col + i][row + j] = '*';
            }
        }
        board[col + 1][row + 1] = ' ';
        return;
    }
    int nextSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            func(board, n, nextSize, col + i * nextSize, row + j * nextSize);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<char>> board(n, vector<char>(n, ' '));
    
    func(board, n, n, 0, 0);

    for (vector<char> a : board) {
        for (char b : a) {
            printf("%c", b);
        }
        printf("\n");
    }
    
 }