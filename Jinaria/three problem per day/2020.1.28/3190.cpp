#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Point {
public:
    int x, y;
    Point():x(0), y(0) {

    }
    Point(int x, int y) :x(x), y(y) {

    }
};

class Info {
public:
    int time;
    char c;
    Info() : time(0), c(' ') {

    }
    Info(int time, char c) :time(time), c(c) {

    }
};

int board[102][102];
bool apple[102][102];

#define UP      1
#define RIGHT   2
#define DOWN    3
#define LEFT    4

void tailmove(Point& tail) {
    
    int& cur_tail = board[tail.y][tail.x];
    switch (cur_tail) {
    case UP:
        tail.y--;
        cur_tail = 0;
        return;
    case RIGHT:
        tail.x++;
        cur_tail = 0;
        return;
    case DOWN:
        tail.y++;
        cur_tail = 0;
        return;
    case LEFT:
        tail.x--;
        cur_tail = 0;
        return;
    }
    return;
}

bool headmove(Point& head, Point& tail) {
    switch (board[head.y][head.x]) {
    case UP:
        if (board[head.y - 1][head.x]) {
            return true;
        }
        else {
            head.y--;
            board[head.y][head.x] = board[head.y + 1][head.x];
        }
        break;
    case RIGHT:
        if (board[head.y][head.x + 1]) {
            return true;
        }
        else {
            head.x++;
            board[head.y][head.x] = board[head.y][head.x - 1];
        }
        break;
    case DOWN:
        if (board[head.y + 1][head.x]) {
            return true;
        }
        else {
            head.y++;
            board[head.y][head.x] = board[head.y - 1][head.x];
        }
        break;
    case LEFT:
        if (board[head.y][head.x - 1]) {
            return true;
        }
        else {
            head.x--;
            board[head.y][head.x] = board[head.y][head.x + 1];
        }
        break;
    }
    if (apple[head.y][head.x])
        apple[head.y][head.x] = false;
    else
        tailmove(tail);
    return false;
}



int main() {
    int N, K, L;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; ++i) {
        int x, y;
        scanf("%d %d", &y, &x);
        apple[y][x] = true;
    }
    scanf("%d", &L);
    vector<Info> info(L);
    for (int i = 0; i < L; ++i)
        scanf("%d %c", &info[i].time, &info[i].c);

    for (int i = 0; i <= N + 1; ++i)
        board[i][0] = board[i][N + 1] = board[0][i] = board[N + 1][i] = -1;
    
    // 1 : up, 2 : right, 3 : down, 4 : left
    board[1][1] = RIGHT;
    Point head(1, 1), tail(1, 1);
    bool flag = false;
    int ans = 0;
    auto iter = info.begin();
    for (int t = 1; ; ++t) {
        if (headmove(head, tail)) {
            ans = t;
            break;
        }
        if (iter != info.end() && t == iter->time) {
            if (iter->c == 'L') {
                board[head.y][head.x] = (board[head.y][head.x] + 2) % 4 + 1;

            }
            else {
                board[head.y][head.x] = board[head.y][head.x] % 4 + 1;
            }
            iter++;
        }
    }
    printf("%d\n", ans);
}