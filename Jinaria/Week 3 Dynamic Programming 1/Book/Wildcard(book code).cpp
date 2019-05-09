#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string W, S;
int cache[101][101];

int check(int w, int s) {
    int pos = 0;
    int &ret = cache[w][s];
    if (ret != -1) return ret;

    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }
    if (w == W.size()) return ret = (s == S.size());

    if (W[w] == '*') {
        for (int skip = 0; skip + s <= S.size(); ++skip) {
            if (check(w + 1, s + skip))
                return ret = 1;
        }
    }
    return ret = 0;
}

int main() {

    int T;
    cin >> T;
    while (T--) {

        int file_num;
        cin >> W >> file_num;
        vector<string> right_files;



        for (int i = 0; i < file_num; i++) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if (check(0, 0)) {
                right_files.push_back(S);
            }
        }
        sort(right_files.begin(), right_files.end());

        for (string file : right_files) {
            cout << file << endl;
        }

    }
}