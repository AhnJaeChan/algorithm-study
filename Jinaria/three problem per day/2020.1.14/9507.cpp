#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M       1000000

long long d[70];

long long koong(int n) {
    if (d[n] != 0)
        return d[n];
    if (n < 2)
        return (d[n] = 1);
    if (n == 2)
        return (d[n] = 2);
    if (n == 3)
        return (d[n] = 4);
    return (d[n] = (koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4)));
}

int main() {
    int t;
    scanf("%d", &t);
    koong(67);
    while (t--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", d[k]);
    }
}