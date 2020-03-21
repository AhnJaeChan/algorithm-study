#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_NUM     1234567890

int state[21][21];

int N;

int func(int level, int startpick, int start, int mask) {
    if (level == N / 2) {
        int tlink = 0;
        for (int i = 0; i < N; ++i) {
            if ((~mask) & (1 << i)) {
                for (int j = i + 1; j < N; ++j) {
                    if ((~mask) & (1 << j)) {
                        tlink += (state[i][j] + state[j][i]);
                    }
                }
            }
        }
        return abs(tlink - start);
    }

    int ret = MAX_NUM;
    for (int i = startpick + 1; i < startpick + 1 + N / 2 && i < N; ++i) {
        int tstart = start;
        for (int j = 0; j < N; ++j) {
            if (j != i && (1 << j) & mask) {
                tstart += (state[i][j] + state[j][i]);
            }
        }
        ret = min(ret, func(level + 1, i, tstart, (mask | (1 << i))));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> state[i][j];
        }
    }

    cout << func(0, -1, 0, 0) << '\n';

}