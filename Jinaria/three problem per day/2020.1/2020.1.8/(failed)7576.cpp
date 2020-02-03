#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define GRAPH(T)    vector<vector<T>>
#define MAX_INT     0x7fffffff

int M, N;


typedef struct {
    int x, y, len;
} Info;

bool validate(GRAPH(int)& tomato, GRAPH(int)& check, int i, int j, int len) {
    if (i < 0 || i >= N) return false;
    if (j < 0 || j >= M) return false;
    if (tomato[i][j]) return false;
    if (check[i][j] <= len) return false;
    return true;
}

int main() {
    scanf("%d %d", &M, &N);
    GRAPH(int) tomato(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &tomato[i][j]);
        }
    }

    queue<Info> q;
    GRAPH(int) check(N, vector<int>(M, MAX_INT));
    int minNum = MAX_INT;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tomato[i][j] == -1)
                check[i][j] = -1;
            if (tomato[i][j] == 1) {
                int maxNum = 0;
                q.push({ i, j, 0});
                while (!q.empty()) {
                    Info tmp = q.front();
                    q.pop();
                    check[tmp.x][tmp.y] = tmp.len;
                    if (maxNum < check[tmp.x][tmp.y])
                        maxNum = check[tmp.x][tmp.y];
                    
                    if (validate(tomato, check, tmp.x - 1, tmp.y, tmp.len)) {
                        q.push({ tmp.x - 1, tmp.y, tmp.len + 1 });
                    }
                    if (validate(tomato, check, tmp.x + 1, tmp.y, tmp.len)) {
                        q.push({ tmp.x + 1, tmp.y, tmp.len + 1 });
                    }
                    if (validate(tomato, check, tmp.x, tmp.y - 1, tmp.len)) {
                        q.push({ tmp.x, tmp.y - 1, tmp.len + 1 });
                    }
                    if (validate(tomato, check, tmp.x, tmp.y + 1, tmp.len)) {
                        q.push({ tmp.x, tmp.y + 1, tmp.len + 1 });
                    }
                    
                }
                if (minNum > maxNum)
                    minNum = maxNum;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check[i][j] == MAX_INT) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (flag)
        printf("%d\n", -1);
    else
        printf("%d\n", minNum);
}  