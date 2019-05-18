#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int cache[101][101];
string W, S;


int match(int w, int s) {
    int &ret = cache[w][s];
    if (ret != -1) {
        return ret;
    }

    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }

    if (w == W.size()) {
        return ret = (s == S.size());
    }

    if (W[w] == '*') {
        for (int offset = 0; offset + s <= S.size(); ++offset) {
            if (match(w + 1, s + 1)) {
                return 1;
            }
        }
    }

    return 0;
}

void resetCache() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            cache[i][j] = -1;
        }
    }
}

int main() {
    int C;
    int n;

    cin >> C;

    for (int i = 0; i < C; ++i) {
        cin >> W >> n;

        for (int j = 0; j < n; ++j) {
            resetCache();

            cin >> S;

            if (match(0, 0) == 1) {
                cout << S << endl;
            }
        }
    }

    return 0;
}
