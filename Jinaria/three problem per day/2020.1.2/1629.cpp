#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    long long k = A;
    long long ret = 1;
    int i = B;
    while (i > 0) {
        if (i & 1) {
            ret *= k;
            ret %= C;
            --i;
            continue;
        }
        k *= k;
        k %= C;
        i >>= 1;
    }
    printf("%lld\n", ret);
}