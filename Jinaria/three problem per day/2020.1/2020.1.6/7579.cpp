#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;


int d[101][10001];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> memory(N + 1);
    for (int i = 1; i <= N; ++i) scanf("%d", &memory[i]);
    vector<int> costs(N + 1);
    for (int i = 1; i <= N; ++i) scanf("%d", &costs[i]);

    memset(d[0], 0, 10001);
    for (int i = 1; i <= N; ++i)
        memset(d[i], -1, 10001);
    for (int i = 1; i <= N; ++i) d[i][0] = 0;
    int cost = 0;
    bool flag = false;
    for (cost = 0; cost <= 10000; ++cost) {
        
        for (int idx = 1; idx <= N; ++idx) {
            if (cost - costs[idx] >= 0)
                d[idx][cost] = max(d[idx][cost], d[idx - 1][cost - costs[idx]] + memory[idx]);
            d[idx][cost] = max(d[idx][cost], d[idx - 1][cost]);
            if (d[idx][cost] >= M) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    printf("%d\n", cost);
}