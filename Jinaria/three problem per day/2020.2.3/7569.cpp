#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define MAX_NUM     1000000007

int tomato[102][102][102];
int dc[] = { 0, 0, 1, 0, -1, 0 };
int dr[] = { 0, 0, 0, 1, 0, -1 };
int dh[] = { -1, 1, 0, 0, 0, 0 };

class Tomato {
public:
    int row, col, height, day;
    Tomato(int row, int col, int height, int day) :row(row), col(col), height(height), day(day) {

    }
};

void bfs(vector<Tomato> &t) {
    queue<Tomato> q;
    for (auto a : t) {
        q.push(a);
    }
    while (!q.empty()) {
        Tomato t = q.front();
        q.pop();
        tomato[t.row][t.col][t.height] = t.day;

        for (int k = 0; k < 6; ++k) {
            int nc = t.col + dc[k];
            int nr = t.row + dr[k];
            int nh = t.height + dh[k];
            if (tomato[nr][nc][nh] > t.day + 1) {
                tomato[nr][nc][nh] = t.day + 1;
                q.push({ nr, nc, nh, t.day + 1 });
            }
        }
    }
}

int main() {
    int N, M, H, t;
    scanf("%d %d %d", &M, &N, &H);
    vector<Tomato> cur;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                scanf("%d", &t);
                if (t == 0)
                    tomato[j][k][i] = MAX_NUM;
                else if (t == 1) {
                    cur.emplace_back(j, k, i, 1);
                    tomato[j][k][i] = t;
                }
                else
                    tomato[j][k][i] = t;
            }
            

        }
    }
    for (int i = 0; i <= N + 1; ++i)
        for(int j = 0; j <= M + 1; ++j)
            tomato[i][j][0] = tomato[i][j][H + 1] = -1;
    for (int i = 0; i <= M + 1; ++i)
        for(int j = 0; j <= H + 1; ++j)
            tomato[0][i][j] = tomato[N + 1][i][j] = -1;
    for (int i = 0; i <= H + 1; ++i)
        for(int j = 0; j <= N + 1; ++j)
            tomato[j][0][i] = tomato[j][M + 1][i] = -1;


    int ans = 0;
    bfs(cur);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            for (int k = 1; k <= H; ++k) {
                if (tomato[i][j][k] == MAX_NUM) {
                    printf("-1\n");
                    return 0;
                }
                ans = max(ans, tomato[i][j][k]);
            }
            
        }
    }
    printf("%d\n", ans - 1);
}