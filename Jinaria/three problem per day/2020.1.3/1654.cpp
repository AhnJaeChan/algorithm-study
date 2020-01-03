#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int K, N;
    scanf("%d %d", &K, &N);
    vector<long long> lansun(K);
    for (int i = 0; i < K; ++i) {
        scanf("%lld", &lansun[i]);
    }
    long long left = 0;
    long long right = 0x7fffffffffffffff;
    long long maxNum = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long result = 0;
        for (int i = 0; i < K; ++i) {
            result += (lansun[i] / mid);
        }
        if (result >= N) {
            left = mid + 1;
            if (maxNum < mid)
                maxNum = mid;
        }
        else {
            right = mid - 1;
        }
    }
    printf("%lld\n", maxNum);
}