#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector<vector<int> > _pascal(1005, vector<int>(1005));
    int n;
    cin >> n;
    _pascal[1][0] = _pascal[1][1] = 1;
    for (int i = 2; i < n; i++) {
        _pascal[i][0] = 1;
        for (int j = 1; j < i; j++) {
            _pascal[i][j] = (_pascal[i - 1][j - 1] + _pascal[i - 1][j]) % 10007;
        }
        _pascal[i][i] = 1;
    }
    _pascal[n][0] = 1;
    int sum = 0;
    for (int i = n; i >= 0; i--) {
        sum += _pascal[i][n - i];
    }
    sum %= 10007;
    cout << sum << endl;
}