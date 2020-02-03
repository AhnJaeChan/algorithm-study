#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d", &N);
        vector<int> coin(N + 1);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &coin[i]);
        scanf("%d", &M);

        int d[21][10001] = {};
        for (int i = 1; i <= N; ++i)
            d[i][0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (j - coin[i] >= 0) {
                    d[i][j] = d[i][j - coin[i]] + d[i - 1][j];
                }
                else
                    d[i][j] = d[i - 1][j];
            }
        }
        printf("%d\n", d[N][M]);
    }
}