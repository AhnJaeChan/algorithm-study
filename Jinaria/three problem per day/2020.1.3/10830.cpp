#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD     1000

typedef vector<vector<int>> Matrix;


Matrix matrix_mul(Matrix &m1, Matrix &m2) {
    Matrix result(m1.size(), vector<int>(m2[0].size()));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            int t = 0;
            for (int k = 0; k < m2.size(); ++k) {
                t += ((m1[i][k] * m2[k][j]) % MOD);
            }
            result[i][j] = t % MOD;
        }
    }
    return result;
}

Matrix matrix_power(Matrix &m, long long B) {
    long long i = B;
    Matrix k(m.size(), vector<int>(m.size(), 0));
    for (int t = 0; t < m.size(); ++t) {
        k[t][t] = 1;
    }
    Matrix s = m;
    while (i > 0) {
        if ((i & 1)) {
            k = matrix_mul(k, s);
            i--;
            continue;
        }
        s = matrix_mul(s, s);
        i >>= 1;
    }
    return k;
}

int main() {
    int N;
    long long B;
    scanf("%d %lld", &N, &B);
    Matrix m(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &m[i][j]);
        }
    }

    Matrix result = matrix_power(m, B);
    for (auto a : result) {
        for (auto b : a) {
            printf("%d ", b);
        }
        printf("\n");
    }

}