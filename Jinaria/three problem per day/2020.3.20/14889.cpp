#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_NUM     1234567890

int stat[21][21];

int N;

int func(int level, int startpick, int start, int link) {
    if (level == N / 2) {

    }

    int ret = MAX_NUM;
    for (int i = 0; i < N / 2 - level; ++i) {
        ret = min(ret, func(level + 1, ))
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> stat[i][j];
        }
    }

    cout << func(0, 0, 0, 0) << '\n';

}