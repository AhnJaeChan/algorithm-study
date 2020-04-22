#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_NUM     123456789
#define V           1
#define H           0
#define U           0
#define R           2
#define D           4
#define L           6

int N;
vector<string> board;
int check[50][50];
char input[51];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int turnx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int turny[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int go[] = { R, D, L, U };
int bx, by, bstate, ex, ey, estate;
int d[50][50][2];

typedef struct {
    int x, y, path, state;
} Info;

bool checkTurn(int x, int y, int state) {
    if (d[y][x][1 - state])
        return false;
    for (int i = 0; i < 8; ++i) {
        int cx = x + turnx[i];
        int cy = y + turny[i];
        if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
            if (board[cy][cx] == '1') {
                return false;
            }
        }
        else {
            return false;
        }
    }
    return true;

}

bool checkGo(int x, int y, int dir, int state) {
    if (state == V) {
        if (dir == U) {
            if (y - 1 >= 0 && d[y - 1][x][state])
                return false;
            if (y - 2 >= 0 && board[y - 2][x] != '1') {
                return true;
            }
            return false;
        }
        if (dir == D) {
            if (y + 1 < N && d[y + 1][x][state])
                return false;
            if (y + 2 < N && board[y + 2][x] != '1') {
                return true;
            }
            return false;
        }
        for (int i = dir; i < dir + 3; ++i) {
            int cx = x + turnx[i];
            int cy = y + turny[i];
            if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
                if (board[cy][cx] == '1') {
                    return false;
                }
            }
            else {
                return false;
            }
            
        }
        return true;
    }
    else {
        if (dir == L) {
            if (x - 2 >= 0 && board[y][x - 2] != '1') {
                return true;
            }
            return false;
        }
        if (dir == R) {
            if (x + 2 < N && board[y][x + 2] != '1') {
                return true;
            }
            return false;
        }
        for (int i = dir; i < dir + 3; ++i) {
            int cx = x + turnx[i];
            int cy = y + turny[i];
            if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
                if (board[cy][cx] == '1') {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
}


int func() {
    queue<Info> q;
    q.push({ bx, by, 0, bstate });
    while (!q.empty()) {
        Info temp = q.front();
        q.pop();
        d[temp.y][temp.x][temp.state] = 1;

        if (temp.x == ex && temp.y == ey && temp.state == estate) {
            return temp.path;
        }
        for (int i = 0; i < 4; ++i) {
            if (checkGo(temp.x, temp.y, go[i], temp.state)) {
                q.push({ temp.x + dx[i], temp.y + dy[i], temp.path + 1, temp.state });
            }
        }
        if (checkTurn(temp.x, temp.y, temp.state)) {
            q.push({ temp.x, temp.y, temp.path + 1, 1 - temp.state });
        }
    }
}

int main() {
    scanf("%d", &N);
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", input);
        board[i] = input;
    }
    
    bool bflag = false, eflag = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!bflag && board[i][j] == 'B') {
                if (i + 1 < N && board[i + 1][j] == 'B') {
                    bx = j, by = i + 1, bstate = V, bflag = true;
                }
                else {
                    bx = j + 1, by = i, bstate = H, bflag = true;
                }
            }
            if (!eflag && board[i][j] == 'E') {
                if (i + 1 < N && board[i + 1][j] == 'E') {
                    ex = j, ey = i + 1, estate = V, eflag = true;
                }
                else {
                    ex = j + 1, ey = i, estate = H, eflag = true;
                }
            }
        }
    }
    int ans = func();
    printf("%d\n", ans);

    return 0;
}