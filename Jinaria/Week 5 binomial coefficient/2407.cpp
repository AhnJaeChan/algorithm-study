#include <iostream>
#include <string>
#include <utility>

using namespace std;

#define DIV 10000000000000LL
pair<long long, long long> a[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) a[i][j] = { 0, 1 };
            else {
                a[i][j].second = a[i - 1][j - 1].second + a[i - 1][j].second;
                a[i][j].first = a[i - 1][j - 1].first + a[i - 1][j].first + a[i][j].second / DIV;
                a[i][j].second %= DIV;
            }
        }
    }
    if (a[n][m].first == 0) {
        cout << a[n][m].second << endl;
    }
    else cout << a[n][m].first << a[n][m].second << endl;//first가 0이 아니면 second 자릿수만큼 맞춰야함


    return 0;
}