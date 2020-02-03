#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int d[101][1001];

int main() {
    int N, S, M;
    scanf("%d %d %d", &N, &S, &M);
    vector<int> V(N + 1);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &V[i]);
    d[0][S] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (d[i - 1][j]) {
                if (j - V[i] >= 0)
                    d[i][j - V[i]] = 1;
                if (j + V[i] <= M)
                    d[i][j + V[i]] = 1;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= M; ++i) {
        if (d[N][i])
            ans = i;
    }
    printf("%d\n", ans);
}