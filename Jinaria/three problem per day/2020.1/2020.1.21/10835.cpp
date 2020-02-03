#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int d[2001][2001];

int N;
int left[2001], right[2001];

int func(int l, int r) {
    if (l > N || r > N)
        return (d[l][r] = 0);
    if (d[l][r] != -1)
        return d[l][r];

    if (left[l] > right[r]) {
        return d[l][r] = max(func(l, r + 1) + right[r], max(func(l + 1, r), func(l + 1, r + 1)));
    }
    else {
        return d[l][r] = max(func(l + 1, r + 1), func(l + 1, r));
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &left[i]);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &right[i]);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            d[i][j] = -1;
    }


    int ans = func(1, 1);
    printf("%d\n", ans);
}