#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define MAX_NUM     1000000007

int tomato[1002][1002];

class Tomato {
public:
    int row, col, day;
    Tomato(int row, int col, int day) :row(row), col(col), day(day) {

    }
};

void bfs(vector<pair<int, int>> &t) {
    queue<Tomato> q;
    for (auto a : t) {
        q.push({ a.first, a.second, 1 });
    }
    while (!q.empty()) {
        Tomato t = q.front();
        q.pop();
        tomato[t.row][t.col] = t.day;
        if (tomato[t.row + 1][t.col] > t.day + 1) {
            tomato[t.row + 1][t.col] = t.day + 1;
            q.push({ t.row + 1, t.col, t.day + 1 });
        }
        if (tomato[t.row - 1][t.col] > t.day + 1) {
            tomato[t.row - 1][t.col] = t.day + 1;
            q.push({ t.row - 1, t.col, t.day + 1 });
        }
        if (tomato[t.row][t.col + 1] > t.day + 1) {
            tomato[t.row][t.col + 1] = t.day + 1;
            q.push({ t.row, t.col + 1, t.day + 1 });
        }
        if (tomato[t.row][t.col - 1] > t.day + 1) {
            tomato[t.row][t.col - 1] = t.day + 1;
            q.push({ t.row, t.col - 1, t.day + 1 });
        }
    }
}

int main() {
    int N, M, k;
    scanf("%d %d", &M, &N);
    vector<pair<int, int>> cur;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &k);
            if (k == 0)
                tomato[i][j] = MAX_NUM;
            else if (k == 1) {
                cur.emplace_back(i, j);
                tomato[i][j] = k;
            }
            else
                tomato[i][j] = k;

        }
    }
    for (int i = 0; i <= N + 1; ++i)
        tomato[i][0] = tomato[i][M + 1] = -1;
    for (int i = 0; i <= M + 1; ++i)
        tomato[0][i] = tomato[N + 1][i] = -1;

    int ans = 0;
    bfs(cur);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (tomato[i][j] == MAX_NUM) {
                printf("-1\n");
                return 0;
            }
            ans = max(ans, tomato[i][j]);
        }
    }
    printf("%d\n", ans - 1);
}