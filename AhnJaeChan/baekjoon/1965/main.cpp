#include <iostream>

#define MAX_N 1000

using namespace std;

int N;
int P[MAX_N + 1];
int F[MAX_N + 1];

int solve() {
    P[0] = F[0] = 0;
    F[1] = 1;
    int max_idx = 0;

    for (int i = 2; i <= N; ++i) {
        F[i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (P[i] > P[j] && F[i] < F[j] + 1) {
                F[i] = F[j] + 1;
            }
        }

        if (F[i] > F[max_idx]) {
            max_idx = i;
        }
    }

    return max_idx;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    cout << F[solve()] << endl;

    return 0;
}