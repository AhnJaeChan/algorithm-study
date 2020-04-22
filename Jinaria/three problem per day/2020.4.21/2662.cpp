#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NUM     123456789

int N, M;
int corp[301][21];
int d[301][21][2];


int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            int k;
            scanf("%d", &k);
            corp[i][j] = k;
        }
    }

    for (int i = 1; i <= N; ++i) {
        d[i][1][0] = corp[i][1];
        d[i][1][1] = i;
    }

    for (int i = 2; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (d[j][i][0] < d[j - k][i - 1][0] + corp[k][i]) {
                    d[j][i][0] = d[j - k][i - 1][0] + corp[k][i];
                    d[j][i][1] = k;
                }
                

            }
        }
    }
    printf("%d\n", d[N][M][0]);
    vector<int> path;
    int cur = d[N][M][1];
    path.push_back(cur);
    int n = N;
    for (int i = M - 1; i > 0; --i) {
        n -= cur;
        path.push_back(d[n][i][1]);
    }
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
   
    return 0;
}