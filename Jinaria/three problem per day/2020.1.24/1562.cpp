#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_INT     -1234567890
#define MAX_INT     1234567890

#define FULL        0b1111111111
#define M           1000000000
int d[101][10][1 << 10];


int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= 9; ++i)
        d[1][i][1 << i] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= FULL; ++k) {
                if (j == 0)
                    d[i][j][k | (1 << j)] = (d[i][j][k | (1 << j)] + d[i - 1][j + 1][k]) % M;
                else if (j == 9)
                    d[i][j][k | (1 << j)] = (d[i][j][k | (1 << j)] + d[i - 1][j - 1][k]) % M;
                else {
                    d[i][j][k | (1 << j)] = (d[i][j][k | (1 << j)] + d[i - 1][j - 1][k]) % M;
                    d[i][j][k | (1 << j)] = (d[i][j][k | (1 << j)] + d[i - 1][j + 1][k]) % M;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; ++i)
        ans = (ans + d[N][i][FULL]) % M;
    printf("%d\n", ans);
}