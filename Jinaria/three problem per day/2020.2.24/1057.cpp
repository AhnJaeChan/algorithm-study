#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int N, kim, lim;
    scanf("%d %d %d", &N, &kim, &lim);

    int round = 1;
    kim--; lim--;
    while ((kim >> 1) != (lim >> 1)) {
        round++;
        kim >>= 1;
        lim >>= 1;
    }
    printf("%d\n", round);
}