#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> maxLength(vector<vector<pair<int, int>>>& tree, int parent, int cur) {
    pair<int, int> maxLen = {0, 0};
    int parentLen = 0;
    for (pair<int, int> tmp : tree[cur]) {
        if (tmp.first == parent) {
            parentLen = tmp.second;
            continue;
        }
        pair<int, int> t = maxLength(tree, cur, tmp.first);
        if (t.second > maxLen.second) {
            maxLen = t;
        }
    }
    if (maxLen.second == 0) return { cur, parentLen };
    return { maxLen.first, maxLen.second + parentLen };
}

int main() {
    int V;
    scanf("%d", &V);
    vector<vector<pair<int, int>>> tree(V + 1);
    for (int i = 0; i < V; ++i) {
        int v, other_v, len;
        scanf("%d %d %d", &v, &other_v, &len);
        while (true) {
            tree[v].push_back({other_v, len});
            scanf("%d", &other_v);
            if (other_v == -1) break;
            scanf("%d", &len);
        }
    }
    pair<int, int> t = maxLength(tree, 0, 1);
    pair<int, int> maxLen = maxLength(tree, 0, t.first);

    printf("%d\n", maxLen.second);
}  