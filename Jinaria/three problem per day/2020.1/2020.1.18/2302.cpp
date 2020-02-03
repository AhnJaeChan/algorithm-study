#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int d[41][3];

int func(int start, int end) {
    if (start >= end)
        return 1;
    d[start][1] = d[start][2] = 1;
    for (int i = start + 1; i < end; ++i) {
        d[i][0] = d[i - 1][2];
        d[i][1] = d[i - 1][0] + d[i - 1][1];
        d[i][2] = d[i - 1][0] + d[i - 1][1];
    }
    d[end][0] = d[end - 1][2];
    d[end][1] = d[end - 1][0] + d[end - 1][1];
    return d[end][0] + d[end][1];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> sit(M);
    for (int i = 0; i < M; ++i)
        scanf("%d", &sit[i]);

    int ans = 1;
    vector<int> result;
    int cur = 1;
    for(int vip : sit){
        ans *= func(cur, vip - 1);
        cur = vip + 1;
    }
    if (cur < N)
        ans *= func(cur, N);
    printf("%d\n", ans);
}