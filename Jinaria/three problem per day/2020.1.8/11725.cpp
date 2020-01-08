#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> tree(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> parent(N + 1);
    for (auto a : tree[1]) {
        parent[a] = 1;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int a : tree[cur]) {
            if (a == parent[cur]) continue;
            q.push(a);
            parent[a] = cur;
        }
    }
    for (int i = 2; i <= N; ++i)
        printf("%d\n", parent[i]);

}  