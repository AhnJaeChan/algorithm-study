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
            int a = d[j][j].first * d[j][j].second * d[j + 1][j + i - 1].second + info[j + 1][j + i - 1];
            int b = info[j][j + i - 2] + d[j][j + i - 2].first * d[j][j + i - 2].second * d[j + i - 1][j + i - 1].second;
            if (a < b) {
                d[j][j + i - 1] = { d[j][j].first, d[j + 1][j + i - 1].second };
                info[j][j + i - 1] = a;
            }
            else {
                d[j][j + i - 1] = { d[j][j + i - 2].first, d[j + i - 1][j + i - 1].second };
                info[j][j + i - 1] = b;
            }
        }
    }
    printf("%d\n", info[1][N]);
 }