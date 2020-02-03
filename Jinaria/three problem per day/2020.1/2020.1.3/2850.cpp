#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long M;
    scanf("%d %lld", &N, &M);
    vector<long long> tree(N);
    for (int i = 0; i < N; ++i)
        scanf("%lld", &tree[i]);

    long long left = 0;
    long long right = 0x7fffffffffffffff;
    long long maxNum = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long result = 0;
        for (int i = 0; i < N; ++i) {
            long long t = tree[i] - mid;
            if (t < 0) continue;
            result += t;
        }
        if (result >= M) {
            left = mid + 1;
            if (mid > maxNum)
                maxNum = mid;
        }
        else {
            right = mid - 1;
        }
    }
    printf("%lld\n", maxNum);
}