#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;


pair<int, int> d[501][501];
int info[501][501];

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> matrix(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &matrix[i].first, &matrix[i].second);
    }

    for (int i = 1; i <= N; ++i) {
        d[i][i] = matrix[i];
    }
    for (int i = 1; i <= N - 1; ++i) {
        d[i][i + 1] = { d[i][i].first, d[i + 1][i + 1].second };
        info[i][i + 1] = d[i][i].first * d[i][i].second * d[i + 1][i + 1].second;
    }

    for (int i = 3; i <= N; ++i) {
        for (int j = 1; j <= N - i + 1; ++j) {
            int minNum = 0x7fffffff;
            for (int k = 0; k < i - 1; k++) {
                minNum = min(minNum, d[j][j + k].first * d[j][j + k].second * d[j + k + 1][j + i - 1].second + info[j][j + k] + info[j + k + 1][j + i - 1]);
            }
            d[j][j + i - 1] = { d[j][j].first, d[j + i - 1][j + i - 1].second };
            info[j][j + i - 1] = minNum;
        }
    }
    printf("%d\n", info[1][N]);
}