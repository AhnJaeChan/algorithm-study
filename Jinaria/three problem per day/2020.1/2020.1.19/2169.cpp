#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_INT     -0x7fffffffLL
#define MAX_INT     0x7fffffffLL
#define LEFT        0
#define RIGHT       1
#define UP          2

int board[1002][1002];
// d[i][j][k] (i, j) 칸에 k 방향에서 왔을 때 최대의 값
long long d[1002][1002][3];


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &board[i][j]);
    
    for (int i = 1; i <= M; ++i) {
        d[1][i][LEFT] = d[1][i - 1][LEFT] + board[1][i];
        d[1][i][RIGHT] = d[1][i][UP] = MIN_INT;
    }
    for (int i = 1; i <= N; ++i) {
        d[i][0][UP] = d[i][0][LEFT] = d[i][0][RIGHT] = MIN_INT;
        d[i][M + 1][UP] = d[i][M + 1][LEFT] = d[i][M + 1][RIGHT] = MIN_INT;
    }
    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            d[i][j][LEFT] = d[i][j][RIGHT] = d[i][j][UP] = MIN_INT;

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            d[i][j][UP] = max(d[i - 1][j][UP], max(d[i - 1][j][LEFT], d[i - 1][j][RIGHT])) + board[i][j];
            d[i][j][LEFT] = max(d[i][j - 1][UP], d[i][j - 1][LEFT]) + board[i][j];
            //d[i][j][RIGHT] = max(d[i][j + 1][UP], d[i][j + 1][RIGHT]) + board[i][j];
        }
        for (int j = M; j > 0; --j) {
            d[i][j][RIGHT] = max(d[i][j + 1][UP], d[i][j + 1][RIGHT]) + board[i][j];
        }
    }
    printf("%lld\n", max(d[N][M][UP], d[N][M][LEFT]));

}