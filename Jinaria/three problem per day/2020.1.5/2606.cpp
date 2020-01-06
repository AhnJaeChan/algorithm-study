#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int network[101][101];

int main() {
    int N;
    scanf("%d", &N);
    int connect;
    scanf("%d", &connect);
    for (int i = 0; i < connect; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        network[a][b] = network[b][a] = 1;
    }

    stack<int> s;
    vector<bool> check(N + 1, false);
    s.push(1);
    int result = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (check[cur]) continue;
        check[cur] = true;
        result++;
        for (int i = 1; i <= N; ++i) {
            if (network[cur][i])
                s.push(i);
        }
    }
    printf("%d\n", result - 1);
}