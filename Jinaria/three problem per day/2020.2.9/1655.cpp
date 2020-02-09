#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    vector<int> nums(N);
    for (int& a : nums)
        scanf("%d", &a);

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    for (int num : nums) {
        if (minheap.size() == maxheap.size()) {
            maxheap.push(num);
        }
        else {
            minheap.push(num);
        }
        if ((!minheap.empty() && !maxheap.empty()) && maxheap.top() > minheap.top()) {
            int a = maxheap.top(); maxheap.pop();
            int b = minheap.top(); minheap.pop();
            maxheap.push(b);
            minheap.push(a);
        }
        ans.push_back(maxheap.top());
    }
    for (int num : ans) {
        printf("%d\n", num);
    }
}