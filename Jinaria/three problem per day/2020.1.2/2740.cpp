#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<vector<int>> matrix_1(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &matrix_1[i][j]);
    scanf("%d %d", &M, &K);
    vector<vector<int>> matrix_2(M, vector<int>(K));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            scanf("%d", &matrix_2[i][j]);

    vector<vector<int>> result(N, vector<int>(K));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            int t = 0;
            for (int k = 0; k < M; ++k) {
                t += (matrix_1[i][k] * matrix_2[k][j]);
            }
            result[i][j] = t;
        }
    }
    for (auto a : result) {
        for (auto b : a) {
            printf("%d ", b);
        }
        printf("\n");
    }

}