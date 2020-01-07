#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define GRAPH(T) vector<vector<T>>

int dfs(GRAPH(int)& pek, GRAPH(bool)& check, int i, int j) {
    if (i < 0 || i >= pek.size()) return 0;
    if (j < 0 || j >= pek[0].size()) return 0;
    if (pek[i][j] == 0)
        return 0;
    if (check[i][j])
        return 0;
    check[i][j] = true;
    int ret = 1;
    ret += (dfs(pek, check, i - 1, j) + dfs(pek, check, i + 1, j) + dfs(pek, check, i, j - 1) + dfs(pek, check, i, j + 1));
    return ret > 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);
        GRAPH(int) pek(N, vector<int>(M, 0));
        int a, b;
        for (int i = 0; i < K; ++i) {
            scanf("%d %d", &a, &b);
            pek[b][a] = 1;
        }
        
        GRAPH(bool) check(N, vector<bool>(M, false));
        int result = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                result += dfs(pek, check, i, j);
            }
        }
        printf("%d\n", result);
    }

}