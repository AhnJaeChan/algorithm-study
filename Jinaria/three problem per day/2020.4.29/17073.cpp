#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NUM     123456789

int N, W;
vector<vector<int>> tree;


int main() {
    scanf("%d %d", &N, &W);
    double w = W;
    double ans = 0;
    
    
    tree.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int leaf_num = 0;
    for (int i = 2; i <= N; ++i) {
        if (tree[i].size() == 1)
            leaf_num++;
    }

    
    ans = w / leaf_num;
    
    printf("%0.6f\n", ans);
    
    return 0;
}