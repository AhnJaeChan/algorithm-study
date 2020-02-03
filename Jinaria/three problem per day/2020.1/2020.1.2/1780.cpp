#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int papers[3];

int paper(vector<vector<int>>& board, int n, int size, int col, int row) {
    if (size == 1) {
        return board[col][row] + 1;
    }
    int arr[4] = { 0, 0, 0, 0 };
    int nextSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int k = paper(board, n, nextSize, col + i * nextSize, row + j * nextSize);
            arr[k]++;
        }
    }
    if (arr[0] == 9)
        return 0;
    if (arr[1] == 9)
        return 1;
    if (arr[2] == 9)
        return 2;
    papers[0] += arr[0];
    papers[1] += arr[1];
    papers[2] += arr[2];
    return 3;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    int t;
    if ((t = paper(board, n, n, 0, 0)) != 3)
        papers[t]++;
    printf("%d\n%d\n%d\n", papers[0], papers[1], papers[2]);
}