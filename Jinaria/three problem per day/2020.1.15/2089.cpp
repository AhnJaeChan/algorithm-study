#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define CHECK(c, x)     ((c) |= (1 << (x))) 
#define UNCHECK(c, x)   ((c) &= ~(1 << (x)))
#define CHECKED(c, x)   ((c) & (1 << (x)))
#define MAX_INT         1234567890

int N;
int W[16][16];
int d[16][1 << 16];
int last;

int func(int cur, int check) {
    
    if (d[cur][check] != 0)
        return d[cur][check];

    if (check == last) {
        if (W[cur][0] == 0)
            return MAX_INT;
        return W[cur][0];
    }

    d[cur][check] = MAX_INT;

    for (int i = 0; i < N; ++i) {
        if (CHECKED(check, i) || W[cur][i] == 0)
            continue;
        int result = func(i, CHECK(check, i)) + W[cur][i];
        UNCHECK(check, i);
        if (result < d[cur][check])
            d[cur][check] = result;
    }
    return d[cur][check];
}

int main() {
    scanf("%d", &N);
    last = (1 << N) - 1;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &W[i][j]);


    int ret = func(0, 1);
    printf("%d\n", ret);
}