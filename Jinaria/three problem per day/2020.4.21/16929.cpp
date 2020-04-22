#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int N, M;
vector<string> board;
int check[50][50];
char input[51];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };


int findCycle(int n, int m, char color, int in, int im, int k) {
    if (k > 4 && n == in && m == im)
        return 1;

    if (check[n][m]) 
        return 0;
    
    check[n][m] = 1;

    int ret = 0;

    for (int i = 0; i < 4; ++i) {
        int cx = n + dx[i];
        int cy = m + dy[i];
        
        if (cx >= 0 && cx < N && cy >= 0 && cy < M && color == board[cx][cy]) {
            ret |= findCycle(cx, cy, color, in, im, k + 1);
        }
    }
    return ret;
}

void initCheck() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            check[i][j] = 0;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    board.resize(N); 
    for (int i = 0; i < N; ++i) {
        scanf("%s", input);
        board[i] = input;
    }

    int flag = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            initCheck();
            flag = findCycle(i, j, board[i][j], i, j, 1);
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if (flag) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}