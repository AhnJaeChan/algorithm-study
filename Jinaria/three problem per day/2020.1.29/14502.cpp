#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x, y;
    Point() :x(0), y(0) {

    }
    Point(int x, int y) : x(x), y(y) {

    }
};

int N, M;
int origin_lab[10][10];
int temp_lab[10][10];

void copyarray() {
    for (int i = 0; i <= N + 1; ++i)
        for (int j = 0; j <= M + 1; ++j)
            temp_lab[i][j] = origin_lab[i][j];
}

void infection(Point& virus) {
    temp_lab[virus.x][virus.y] = 2;
    Point v1(virus.x + 1, virus.y), v2(virus.x - 1, virus.y), v3(virus.x, virus.y - 1), v4(virus.x, virus.y + 1);
    if (temp_lab[virus.x + 1][virus.y] == 0)
        infection(v1);
    if (temp_lab[virus.x - 1][virus.y] == 0)
        infection(v2);
    if (temp_lab[virus.x][virus.y - 1] == 0)
        infection(v3);
    if (temp_lab[virus.x][virus.y + 1] == 0)
        infection(v4);
}

int room() {
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (temp_lab[i][j] == 0)
                ++ret;
            else if (origin_lab[i][j] == 0 && temp_lab[i][j] == 2)
                temp_lab[i][j] = 0;
        }
    }
        
    return ret;
}

int dfs(int row, int col, int wall, vector<Point> &virus) {
    if (wall == 2) {
        temp_lab[row][col] = 1;
        for (Point& v : virus) {
            infection(v);
        }
        int ret = room();
        temp_lab[row][col] = 0;
        return ret;
    }
    temp_lab[row][col] = 1;
    int ret = 0;
    for (int j = col + 1; j <= M; ++j) {
        if (temp_lab[row][j] != 0)
            continue;
        ret = max(ret, dfs(row, j, wall + 1, virus));
    }
    for (int i = row + 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (temp_lab[i][j] != 0)
                continue;
            ret = max(ret, dfs(i, j, wall + 1, virus));
        }
    }
    temp_lab[row][col] = 0;
    return ret;
}


int main() {
    scanf("%d %d", &N, &M);
    vector<Point> virus;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &origin_lab[i][j]);
            if (origin_lab[i][j] == 2)
                virus.emplace_back(i, j);
        }

    for (int i = 0; i <= N + 1; ++i)
        origin_lab[i][0] = origin_lab[i][M + 1] = 1;
    for (int i = 0; i <= M + 1; ++i)
        origin_lab[0][i] = origin_lab[N + 1][i] = 1;

    int ans = 0;


    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (origin_lab[i][j] != 0)
                continue;
            copyarray();
            ans = max(ans, dfs(i, j, 0, virus));
        }
    }

    printf("%d\n", ans);
}