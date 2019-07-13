#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>

using namespace std;

int cache[1000][1000];
int kmax = 0;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> temp(n);
    vector<vector<int> > square(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            square[i][j] = temp[i][j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                cache[i][j] = square[i][j];
                if (cache[i][j] > kmax) kmax = cache[i][j];
                continue;
            }
            int tmax = 1234567890;
            if (square[i][j] == 0) continue;
            for (int k = 1; k <= 3; k++) {
                if (cache[i - k % 2][j - k / 2] < tmax) tmax = cache[i - k % 2][j - k / 2];
            }
            cache[i][j] = tmax + 1;
            if (kmax < cache[i][j]) kmax = cache[i][j];
        }
    }

    cout << kmax * kmax << endl;

    return 0;
}