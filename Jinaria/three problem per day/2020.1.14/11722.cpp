#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);

    reverse(nums.begin(), nums.end());

    vector<int> save;
    for (int num : nums) {
        if (save.empty() || save.back() < num) {
            save.push_back(num);
        }
        else {
            vector<int>::iterator iter = lower_bound(save.begin(), save.end(), num);
            *iter = num;
        }
    }
    printf("%d\n", save.size());
}