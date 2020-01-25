#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> matrix[1001];

bool check[1001];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    int ans = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (check[i])
            continue;
        queue<int> q;
        q.push(i);
        check[i] = true;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int num : matrix[t]) {
                if (check[num])
                    continue;
                check[num] = true;
                q.push(num);
            }
        }
        ans++;
    }
    printf("%d\n", ans);
}