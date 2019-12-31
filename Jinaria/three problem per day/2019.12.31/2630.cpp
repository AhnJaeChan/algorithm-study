#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define WHITE       0
#define BLUE        4
#define DUMMY       5
#define BOARD_SIZE  200


int white, blue;
int board[BOARD_SIZE][BOARD_SIZE];

int quadtree(int n, int size, int col, int row) {
    if (size == 1) {
        return board[col][row];
    }
    int ret = 0;
    int nextSize = size >> 1;
    for (int i = 0; i < 4; ++i) {
        ret += quadtree(n, nextSize, col + (i >> 1)* nextSize, row + (i & 1) * nextSize);
    }
    if (ret == 0) return 0;
    if (ret == BLUE) return 1;
    int t = 4 - ret / DUMMY;
    blue += (ret % DUMMY);
    white += (t - ret % DUMMY);
    return DUMMY;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    int result = quadtree(n, n, 0, 0);
    if (result == WHITE) white++;
    else if (result == BLUE) blue++;


    printf("%d\n%d\n", white, blue);
}