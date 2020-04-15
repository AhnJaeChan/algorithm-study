#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MID     40000

int N, W;
int biz[31];
int toChk[7];

int d[80001][32];


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &biz[i]);
    scanf("%d", &W);
    for (int i = 0; i < W; ++i)
        scanf("%d", &toChk[i]);


    d[MID][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= 80000; ++j) {
            if (d[j][i - 1]) {
                d[j][i] = 1;
                if (j - biz[i] >= 0) {
                    d[j - biz[i]][i] = 1;
                    d[j - biz[i]][31] = 1;
                }
                if (j + biz[i] <= 80000) {
                    d[j + biz[i]][i] = 1;
                    d[j + biz[i]][31] = 1;
                }
            }
        }
    }


    for (int chk = 0; chk < W; ++chk) {
        if (d[toChk[chk] + MID][31]) {
            printf("Y ");
        }
        else {
            printf("N ");
        }
    }
    printf("\n");

    return 0;
}