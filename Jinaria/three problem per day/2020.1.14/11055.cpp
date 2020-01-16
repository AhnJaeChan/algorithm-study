#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int d[1001];

int main() {
    int N;
    scanf("%d", &N);
    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &nums[i]);
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int maxNum = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (maxNum < d[j])
                    maxNum = d[j];
            }
        }
        d[i] = maxNum + nums[i];
        if (d[i] > ans)
            ans = d[i];
    }

    printf("%d\n", ans);
}