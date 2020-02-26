#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int d[1001][1001];

int main() {
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    
    int N = A.size();
    int M = B.size();
    for (int i = 1; i <= N; ++i) {
        char cur = A[i - 1];
        for (int j = 1; j <= M; ++j) {
            if (B[j - 1] == cur) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    stack<char> s;
    int i = N, j = M;
    while (d[i][j] > 0) {
        if (d[i][j] == d[i - 1][j]) {
            i--;
        }
        else if (d[i][j] == d[i][j - 1]) {
            j--;
        }
        else if (d[i][j] - 1 == d[i - 1][j - 1]){
            s.push(A[i - 1]);
            i--; j--;
        }
    }

    string ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << d[N][M] << '\n' << ans << '\n';
}