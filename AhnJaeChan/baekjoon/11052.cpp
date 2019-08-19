#include <iostream>
#include <string>

#define MAX_N 1000

using namespace std;

int N;
int P[MAX_N + 1];
int F[MAX_N + 1];

inline int max(int a, int b) {
    return a > b ? a : b;
}

void solve() {
    P[0] = F[0] = 0;
    F[1] = P[1];

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            F[i] = max(F[i], F[i - j] + P[j]);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    solve();

    cout << F[N] << endl;

    return 0;
}
