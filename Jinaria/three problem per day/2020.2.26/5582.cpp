#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int d[4001][4001];

int main() {
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    int ans = 0;
    int N = A.size(), M = B.size();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i - 1] == B[j - 1]) {
                d[i][j] = d[i - 1][j - 1] + 1;
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans << '\n';
}   