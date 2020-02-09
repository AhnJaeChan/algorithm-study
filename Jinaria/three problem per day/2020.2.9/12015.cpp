#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> nums(N);
    for (int &a : nums)
        scanf("%d", &a);

    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < N; ++i) {
        auto cur = lower_bound(ans.begin(), ans.end(), nums[i]);
        if (cur == ans.end()) {
            ans.push_back(nums[i]);
        }
        else {
            *cur = nums[i];
        }
    }
    printf("%d\n", ans.size());
}