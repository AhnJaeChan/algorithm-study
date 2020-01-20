#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_K       1000000000

int c[201][201];
char ans[401];

int avail(int a, int b) { return c[a + b][b]; }
int idx = 0;

void func(int n, int m, int k, int len) {
    if (len <= 0)
        return;
    if (n == 0) {
        ans[idx++] = 'z';
        func(n, m - 1, k - avail(n - 1, m), len - 1);
    }
    else if (m == 0) {
        ans[idx++] = 'a';
        func(n - 1, m, k, len - 1);
    }
    else if (avail(n - 1, m) >= k) {
        ans[idx++] = 'a';
        func(n - 1, m, k, len - 1);
    }
    else {
        ans[idx++] = 'z';
        func(n, m - 1, k - avail(n - 1, m), len - 1);
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= N + M; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = min(MAX_K, c[i - 1][j - 1] + c[i - 1][j]);
        }
    }
    if (K > avail(N, M)) {
        printf("-1\n");
        return 0;
    }

    func(N, M, K, N + M);
    ans[idx] = '\0';
    printf("%s\n", ans);

}