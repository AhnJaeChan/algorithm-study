#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int d[100001];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= 100000; ++i)
        d[i] = -1;

    queue<pair<int, int>> q;
    q.push({ N, 0 });
    int ans = 0;
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        if (d[tmp.first] != -1 && d[tmp.first] < tmp.second)
            continue;
        d[tmp.first] = tmp.second;
        if (tmp.first == K) {
            ans = tmp.second;
            break;
        }
        if (tmp.first - 1 >= 0)
            q.push({ tmp.first - 1, tmp.second + 1 });
        if (tmp.first + 1 <= 100000)
            q.push({ tmp.first + 1, tmp.second + 1 });
        if (tmp.first * 2 <= 100000)
            q.push({ tmp.first * 2, tmp.second + 1 });
    }
    printf("%d\n", ans);
}