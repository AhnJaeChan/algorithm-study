#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define GRAPH(T) vector<vector<T>>



typedef struct {
    int x;
    int y;
    int len;
} info;

bool validate(GRAPH(int) &miro, GRAPH(bool) &check, int i, int j) {
    if (i < 0 || i >= miro.size()) return false;
    if (j < 0 || j >= miro[0].size()) return false;
    if (miro[i][j] == 0) return false;
    if (check[i][j]) return false;
    
    return true;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    GRAPH(int) miro(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            while ((miro[i][j] = getchar()) == '\n');
            miro[i][j] -= '0';
        }
    }
    queue<info> q;
    GRAPH(bool) check(N, vector<bool>(M, false));
    q.push({ 0, 0, 1 });
    int minlen;
    while (!q.empty()) {
        info tmp = q.front();
        q.pop();
        if (check[tmp.x][tmp.y]) continue;
        if (tmp.x == N - 1 && tmp.y == M - 1) {
            minlen = tmp.len;
            break;
        }
        check[tmp.x][tmp.y] = true;
        if (validate(miro, check, tmp.x - 1, tmp.y))
            q.push({ tmp.x - 1, tmp.y, tmp.len + 1 });
        if (validate(miro, check, tmp.x + 1, tmp.y))
            q.push({ tmp.x + 1, tmp.y, tmp.len + 1 });
        if (validate(miro, check, tmp.x, tmp.y - 1))
            q.push({ tmp.x, tmp.y - 1, tmp.len + 1 });
        if (validate(miro, check, tmp.x, tmp.y + 1))
            q.push({ tmp.x, tmp.y + 1, tmp.len + 1 });
    }
    printf("%d\n", minlen);
}