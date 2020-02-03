#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define M           1000000007

long long d[101][101][101];

int main() {
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);

    d[1][1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int l = 1; l <= L; ++l) {
            for (int r = 1; r <= R; ++r) {
                d[i][l][r] = (d[i - 1][l - 1][r] + d[i - 1][l][r - 1] + d[i - 1][l][r] * (i - 2)) % M;
            }
        }
    }

    printf("%lld\n", d[N][L][R]);
}