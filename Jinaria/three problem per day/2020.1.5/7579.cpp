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

    for (int i = 0; i <= N; ++i)
        memset(d[i], -1, 10001);
    for (int i = 0; i <= N; ++i) d[i][0] = 0;
    int cost = 0;
    for (cost = 0; cost <= 10000; ++cost) {
        int maxMem = -1;
        int idx = -1;
        for()
        for (int j = 1; j <= N; ++j) {
            if (cost - costs[j] >= 0) {
                if (maxMem < memory[j] + d[j][cost - costs[j]]) {
                    maxMem = memory[j] + d[j][cost - costs[j]];
                    idx = j;
                }
                d[j][cost] = d[j][cost - costs[j]] + memory[j];
            }
        }
        if (maxMem >= M) {
            break;
        }
    }
    printf("%d\n", cost);
}