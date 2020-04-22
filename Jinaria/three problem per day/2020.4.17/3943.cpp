#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NUM     123456789

int T, N;

int d[1000001];

int func(int n) {
    if (n == 1) {
        return 0;
    }
    if (n <= 1000000 && d[n]) {
        return d[n];
    }

    int ret = 0;
    if (n & 1) {
        ret = func(n * 3 + 1);
    }
    else {
        ret = func(n >> 1);
    }
    if (n <= 1000000)
        d[n] = max(n, ret);

    return max(n, ret);
}

int main() {
    
    for (int i = 1; i < 1000000; i <<= 1) {
        d[i] = i;
    }


    for (int i = 2; i <= 100000; ++i) {
        d[i] = func(i);
    }
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);

        printf("%d\n", d[N]);
    }

    return 0;
}