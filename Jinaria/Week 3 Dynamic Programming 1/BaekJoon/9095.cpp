#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int _num[11];

int find_num(int n) {
    if (_num[n] != -1) return _num[n];
    if (n == 1) {
        return _num[n] = 1;
    }
    if (n == 2) {
        return _num[n] = 2;
    }
    if (n == 3) {
        return _num[n] = 4;
    }
    int sum = 0;
    for (int i = 1; i <= 3; i++) {
        sum += find_num(n - i);
    }
    return _num[n] = sum;
}

int main() {
    int T;
    cin >> T;
    memset(_num, -1, sizeof(_num));
    while (T--) {
        int n;
        cin >> n;
        cout << find_num(n) << endl;
    }
}