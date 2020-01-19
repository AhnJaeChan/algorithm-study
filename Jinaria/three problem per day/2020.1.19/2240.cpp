#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_INT     -1234567890
#define MAX_INT     1234567890

int d[1001][31];

int main() {
    int T, W;
    scanf("%d %d", &T, &W);
    vector<int> tree(T + 1);
    for (int i = 1; i <= T; ++i)
        scanf("%d", &tree[i]);

    int prum = 0;
    for (int i = 1; i <= T; ++i) {
        if (tree[i] == 1)
            ++prum;
        d[i][0] = prum;
    }

    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (tree[j] == 1) {
                if (i & 1) {
                    d[j][i] = max(d[j - 1][i], d[j][i - 1]);
                }
                // 자두를 얻는 경우
                else {
                    d[j][i] = max(d[j - 1][i], d[j][i - 1]) + 1;
                }
            }
            else {
                // 자두를 얻는 경우
                if (i & 1) {
                    d[j][i] = max(d[j - 1][i], d[j][i - 1]) + 1;
                }
                else {
                    d[j][i] = max(d[j - 1][i], d[j][i - 1]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; ++i)
        if (ans < d[T][i])
            ans = d[T][i];

    printf("%d\n", ans);

}