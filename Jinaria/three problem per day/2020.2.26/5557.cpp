#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long d[101][21];

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> numbers(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> numbers[i];

    d[1][numbers[1]] = 1;
    for (int i = 2; i < N; ++i) {
        int cur = numbers[i];
        for (int j = 0; j <= 20; ++j) {
            if (j - cur >= 0) {
                d[i][j - cur] += d[i - 1][j];
            }
            if (j + cur <= 20) {
                d[i][j + cur] += d[i - 1][j];
            }
        }
    }
    long long ans = d[N - 1][numbers[N]];
    cout << ans << '\n';
}