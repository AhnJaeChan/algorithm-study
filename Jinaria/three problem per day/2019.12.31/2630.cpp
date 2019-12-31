#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define WHITE       0
#define BLUE        1
#define DUMMY       2
#define BOARD_SIZE  20


int white, blue;

int quadtree(int *arr, int n, int size) {
    if (size == 1) {
        return *arr;
    }
    int ret = 0;
    int nextSize = size / 2;
    for (int i = 0; i < 4; ++i) {
        ret += quadtree(arr + (i >> 1) * n * nextSize + (i & 1) * nextSize, n, nextSize);
    }
    if (ret < BLUE) {
        return WHITE;
    }
    else if (ret < DUMMY) {
        return BLUE;
    }
    else {
        int t = n - ret / DUMMY;
        blue += (ret % DUMMY);
        white += (t - ret % DUMMY);
        return DUMMY;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* board = (int*)malloc(sizeof(int) * n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i * n + j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", board[i * n + j]);
        }
        printf("\n");
    }
    //int result = quadtree(board, n, n);
    //if (result == WHITE) white++;
    //else if (result == BLUE) blue++;

    //printf("%d\n%d\n", white, blue);
 }