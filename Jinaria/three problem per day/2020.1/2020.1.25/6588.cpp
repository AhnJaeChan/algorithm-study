#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


#define MAX_NUM     1000000

bool prime[MAX_NUM + 1];

int main() {

    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i <= MAX_NUM; ++i) {
        for (int j = i + i; j <= MAX_NUM; j += i) {
            prime[j] = true;
        }
    }

    while (true) {
        int N;
        scanf("%d", &N);
        if (N == 0)
            break;
        int a = -1, b = N;
        if (!(N & 1))
            b--;
        for (int i = b; i > 0; i -= 2) {
            if (!prime[i]) {
                if (!prime[N - i]) {
                    b = i;
                    a = N - i;
                    break;
                }
            }
        }
        if (a == -1)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n", N, a, b);

    }
}