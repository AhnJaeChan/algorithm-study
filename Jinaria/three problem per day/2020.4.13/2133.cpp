#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int N;

int d[31];
int d2[29];

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    if (N & 1) {
        cout << 0 << '\n';
        return 0;
    }

    d[2] = 3;
    d[4] = 11;
    for (int i = 6; i <= N; i = i + 2) {
        d[i] = d[i - 2] * d[2] + 2;
        for (int j = 4; j < i; ++j) {
            d[i] = d[i] + d[i - j] * 2;
        }
    }
    cout << d[N] << '\n';
    return 0;

}