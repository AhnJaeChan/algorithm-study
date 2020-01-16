#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int first[16][16];
int second[16][16];

int func(int n, int m, bool flag) {
    if (flag) {
        for (int i = 1; i <= n; ++i)
            first[i][1] = 1;
        for (int i = 1; i <= m; ++i)
            first[1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                first[i][j] = first[i - 1][j] + first[i][j - 1];
            }
        }
        return first[n][m];
    }
    for (int i = 1; i <= n; ++i)
        second[i][1] = 1;
    for (int i = 1; i <= m; ++i)
        second[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            second[i][j] = second[i - 1][j] + second[i][j - 1];
        }
    }
    return second[n][m];
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    pair<int, int> k;
    if (K) {
        k.first = (K - 1) / M + 1;
        k.second = (K - 1) % M + 1;
        printf("%d\n", func(k.first, k.second, true) * func(N - k.first + 1, M - k.second + 1, false));
    }
    else {
        printf("%d\n", func(N, M, true));
    }
}