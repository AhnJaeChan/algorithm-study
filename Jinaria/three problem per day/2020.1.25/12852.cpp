#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX_INT     1234567890

int d[100001];
int p[100001];

int func(int n) {
    if (d[n] != -1)
        return d[n];

    if (n == 1)
        return d[n] = 0;

    int out, minnum = MAX_INT;
    int three, two, one;
    if (n % 3 == 0) {
        three = func(n / 3);
        if (minnum > three) {
            minnum = three;
            out = n / 3;
        }
    }
    if (n % 2 == 0) {
        two = func(n / 2);
        if (minnum > two) {
            minnum = two;
            out = n / 2;
        }
    }
    one = func(n - 1);
    if (minnum > one) {
        minnum = one;
        out = n - 1;
    }
    p[n] = out;
    return d[n] = ++minnum;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        d[i] = -1;

    int ans = func(N);
    printf("%d\n", ans);

    printf("%d ", N);
    while (p[N] > 0) {
        printf("%d ", p[N]);
        N = p[N];
    }

     return 0;
}