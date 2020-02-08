#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_RANGE     1000000001


int main() {
    int N, k;
    scanf("%d %d", &N, &k);


    int start = 1, end = k;
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            result += min(mid / i, N);
        }
        if (result < k) {
            start = mid + 1;
        }
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    printf("%d\n", ans);

}