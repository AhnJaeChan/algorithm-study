#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> graph(N + 1);
    vector<int> edge(N + 1);
    for (int i = 0; i < M; ++i) {
        int k, t;
        scanf("%d", &k);
        int cur;
        scanf("%d", &cur);
        for (int j = 0; j < k - 1; ++j) {
            scanf("%d", &t);
            graph[cur].push_back(t);
            edge[t]++;
            cur = t;
        }
    }

    queue<int> q;
    vector<bool> check(N + 1, false);
    for (int i = 1; i <= N; ++i)
        if (edge[i] == 0) {
            check[i] = true;
            q.push(i);
        }
    vector<int> ans;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int a : graph[t]) {
            edge[a]--;
            if (!check[a] && edge[a] == 0) {
                check[a] = true;
                q.push(a);
            }
        }
    }

    if (ans.size() < N)
        printf("0\n");
    else {
        for (int a : ans) {
            printf("%d\n", a);
        }
    }
    
    return 0;
}