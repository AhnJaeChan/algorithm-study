#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

#define MAX_INF     0x7fffffff


typedef vector<vector<pair<int, int>>> vvp;

int main() {
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    vvp graph(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({ v, w });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> d;
    vector<int> dist(V + 1, MAX_INF);
    d.push({ 0, K });
    dist[K] = 0;
    while (!d.empty()) {
        pair<int, int> t = d.top();
        d.pop();
        if (t.first > dist[t.second])
            continue;
        for (auto &a : graph[t.second]) {
            if (dist[a.first] > t.first + a.second) {
                dist[a.first] = t.first + a.second;
                d.push({ dist[a.first], a.first });
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == MAX_INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}
