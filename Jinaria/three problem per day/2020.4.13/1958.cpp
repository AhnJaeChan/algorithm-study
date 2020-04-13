#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX_NUM     123456789

int d1[101][101];
int d2[101][101];
int d[101][101][101];

string A, B, C;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> A >> B >> C;

    
    int N = A.size();
    int M = B.size();
    int L = C.size();

    for (int i = 1; i <= N; ++i) {
        char cur = A[i - 1];
        for (int j = 1; j <= M; ++j) {
            for (int k = 1; k <= L; ++k) {
                if (B[j - 1] == cur && C[k - 1] == cur) {
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
                }
            }
        }
    }
    cout << d[N][M][L] << '\n';



    return 0;

}