#include<iostream>

#define MOD 10007

using namespace std;

int pascal[1005][1005];

int main() {
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
            }
        }
    }

    int N, K;
    cin >> N >> K;
    cout << pascal[N][K] << '\n';
}