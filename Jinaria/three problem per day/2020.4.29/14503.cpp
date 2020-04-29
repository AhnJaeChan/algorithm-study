#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789
#define N           0
#define E           1
#define S           2
#define W           3

int n, m;
int room[50][50];
int robot_x, robot_y, robot_dir;
int check[50][50];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool canGo(int r, int c, int dir) {
    int nx = c + dx[dir];
    int ny = r + dy[dir];
    if (nx < m && nx >= 0 && ny < n && ny >= 0 && check[ny][nx] == 0) {
        return true;
    }
    return false;
}

int func(int r, int c, int dir) {
    int ret = 0;
    if (check[r][c]) {

    }
    else {
        check[r][c] = 2;
        ret++;
        int add = 0;
        for (int i = 0; i < 4; ++i) {
            int tdir = (dir + 3 - i) % 4;
            
            if (canGo(r, c, tdir)) {
                int nx = c + dx[tdir];
                int ny = r + dy[tdir];
                add += func(ny, nx, tdir);
            }
        }
        if(add)
    }
    if()
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &robot_x, &robot_y, &robot_dir);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &room[i][j]);
            check[i][j] = room[i][j];
        }
    }





    return 0;
}