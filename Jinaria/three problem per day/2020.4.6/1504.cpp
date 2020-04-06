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

int getDist(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({ 0, start });
    vector<bool> check(N + 1, false);
    check[start] = true;
    while (!heap.empty()) {
        pair<int, int> temp = heap.top();
        heap.pop();
        if (temp.second == end) {
            return temp.first;
        }
        
        //for (auto it = city[temp.second].begin(); it != city[temp.second].end(); ++it) {
        for(int i = 1; i <= N; ++i){
            //if (check[it->first])
            if(city[temp.second][i] == 0 || check[i] || i == temp.second)
                continue;
            heap.push({ temp.first + city[temp.second][i], i });
            check[i] = true;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);

    
    cin >> N >> E;
    //city.assign(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        //city[a].push_back({ b, c });
        //city[b].push_back({ a, c });
        city[a][b] = city[b][a] = c;
    }
    cin >> node[1] >> node[2];

    //int d11 = getDist(1, v1), d12 = getDist(v1, v2), d13 = getDist(v2, N);
    //int d21 = getDist(1, v2), d22 = getDist(v2, v1), d23 = getDist(v1, N);

    int ans = 0;
    if (d11 && d12 && d13) {
        ans = d11 + d12 + d13;
        if (d21 && d22 && d23) {
            ans = min(ans, d21 + d22 + d23);
        }
    }
    if (ans == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}