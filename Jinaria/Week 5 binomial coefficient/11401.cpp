#include <iostream>

#define MOD 1000000007

using namespace std;

long long factorial[4000005];
long long x, y, gcd, temp;

void euclidean(long long B, long long p) {
    if (B % p > 0) {
        euclidean(p, B % p);
        temp = y;
        y = x - (B / p) * y;
        x = temp;
    }
    else {
        x = 0;
        y = 1;
        gcd = p;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= N; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    long long denominator = (factorial[K] * factorial[N - K]) % MOD;
    euclidean(MOD, denominator);
    long result = ((factorial[N] % MOD) * y % MOD) % MOD;
    if (result < 0) result += MOD;
    cout << result << '\n';
}