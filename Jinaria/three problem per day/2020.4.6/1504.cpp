#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define MAX_NUM     123456789


int city[801][801];
int dist[3][801];
int node[3] = { 1, 0, 0 };
//vector<vector<pair<int, int>>> city;


int N, E;

void func() {
    for (int start = 0; start < 3; ++start) {
        priority_queue<pair<int, int>> heap;
        heap.push({ 0, node[start] });
        dist[start][node[start]] = 0;
        while (!heap.empty()) {
            int cur = heap.top().second;
            int cur_cost = -heap.top().first;
            heap.pop();
            if (dist[start][cur] < cur_cost) continue;
            for (int next = 1; next <= N; ++next) {
                if (city[cur][next] && dist[start][next] > cur_cost + city[cur][next]) {
                    dist[start][next] = cur_cost + city[cur][next];
                    heap.push({ -dist[start][next], next });
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);


    cin >> N >> E;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = city[b][a] = c;
    }   
    cin >> node[1] >> node[2];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= N; ++j) {
            dist[i][j] = MAX_NUM;
        }
    }

    func();
    int ans = min(dist[0][node[1]] + dist[1][node[2]] + dist[2][N], dist[0][node[2]] + dist[2][node[1]] + dist[1][N]);

    if (ans >= MAX_NUM) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}