#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int T, N;

string magic, bridge[2];
char m[21], b[101];

int d[21][101][2];

int main() {
    ios::sync_with_stdio(false);
    scanf("%s", m);
    magic = m;
    scanf("%s", b);
    bridge[0] = b;
    scanf("%s", b);
    bridge[1] = b;

    for (int j = 0; j < bridge[0].size(); ++j) {
        for (int k = 0; k < 2; ++k) {
            d[1][j + 1][k] = d[1][j][k];
            if (magic[0] == bridge[k][j]) {
                d[1][j + 1][k]++;
            }
        }
    }

    for (int i = 1; i < magic.size(); ++i) {
        char cur = magic[i];
        int curidx = i + 1;
        // 0 : engel, 1 : devil
        for (int j = 0; j < bridge[0].size(); ++j) {
            int curloc = j + 1;
            for (int k = 0; k < 2; ++k) {
                d[curidx][curloc][k] = d[curidx][curloc - 1][k];
                if (cur == bridge[k][j])
                    d[curidx][curloc][k] += d[curidx - 1][curloc - 1][1 - k];
            }
        }
    }
    
    printf("%d\n", d[magic.size()][bridge[0].size()][0] + d[magic.size()][bridge[1].size()][1]);

    return 0;

}